#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>


#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <asm/mach/map.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <asm/io.h>
#include <linux/device.h>

#include <linux/platform_device.h>


/*------------------字符设备内容----------------------*/
#define DEV_NAME               "beep"
#define DEV_CNT                 (1)

//定义字符设备的设备号
static dev_t beep_devno;
//定义字符设备结构体chr_dev
static struct cdev beep_chr_dev;

struct class *class_beep;	//保存创建的类
struct device *device;	    // 保存创建的设备
struct device_node	*beep_device_node; //RGB led的设备树节点

int beep_gpr;

static DEFINE_SPINLOCK(read_lock);

/*字符设备操作函数集，open函数*/
static int beep_chr_dev_open(struct inode *inode, struct file *filp)
{
	printk("\n open form driver \n");
    return 0;
}

/*字符设备操作函数集，write函数*/
static ssize_t beep_chr_dev_write(struct file *filp, const char __user *buf, size_t cnt, loff_t *offt)
{
	
	unsigned char write_data; //用于保存接收到的数据

	int error = copy_from_user(&write_data, buf, cnt);
	if(error < 0) {
		return -1;
	}

    /*设置 GPIO1_19 输出电平*/
	if(write_data & 0x01)
	{
		gpio_direction_output(beep_gpr, 1);  // 蜂鸣器响
	}
	else
	{
		gpio_direction_output(beep_gpr, 0);  // 蜂鸣器不响
	}

	return 0;
}

static ssize_t beep_chr_dev_read(struct file *filp, char __user *buf, size_t cnt, loff_t *offt)
{
	unsigned long flag = 0;
	unsigned char read_data = 0,read_flag = 0; //用于保存接收到的数据
	int error;

	spin_lock_irqsave(&read_lock, flag);
	if((read_flag = gpio_get_value(beep_gpr)) >= 0)
		read_data = 1;
	else{
		printk(KERN_EMERG "\t  read red_led error  \n");
		return -1;
	}
	spin_unlock_irqrestore(&read_lock, flag);

	error = copy_to_user(buf, &read_data, 1);    //内核空间读取的数据拷贝到用户空间
	if(error < 0) {
		printk(KERN_EMERG "\t  copy to user error  \n");
		return -1;
	}

	return 1;
}



/*字符设备操作函数集*/
static struct file_operations  beep_chr_dev_fops = 
{
	.owner = THIS_MODULE,
    .open = beep_chr_dev_open,
	.write = beep_chr_dev_write,
	.read = beep_chr_dev_read,
};

/*----------------平台驱动函数集-----------------*/
static int beep_probe(struct platform_device *pdv)
{
	int ret = 0;  //用于保存申请设备号的结果
    
	printk(KERN_EMERG "\t  match successed  \n");

	/*获取beep的设备树节点*/
    beep_device_node = of_find_node_by_path("/beep");
    if(beep_device_node == NULL)
    {
        printk(KERN_EMERG "\t  get beep failed!  \n");
    }

	beep_gpr = of_get_named_gpio(beep_device_node, "beep_gpr", 0);

	printk("beep_gpr = %d \n",beep_gpr);

	gpio_direction_output(beep_gpr, 0);   //初始化输出低电平


	/*---------------------注册 字符设备部分-----------------*/

	//第一步
    //采用动态分配的方式，获取设备编号，次设备号为0，
    //设备名称为beep，可通过命令cat  /proc/devices查看
    //DEV_CNT为1，当前只申请一个设备编号
    ret = alloc_chrdev_region(&beep_devno, 0, DEV_CNT, DEV_NAME);
    if(ret < 0){
        printk("fail to alloc led_devno\n");
        goto alloc_err;
    }
	//第二步
    //关联字符设备结构体cdev与文件操作结构体file_operations
	beep_chr_dev.owner = THIS_MODULE;
    cdev_init(&beep_chr_dev, &beep_chr_dev_fops);
	//第三步
    //添加设备至cdev_map散列表中
    ret = cdev_add(&beep_chr_dev, beep_devno, DEV_CNT);
    if(ret < 0)
    {
        printk("fail to add cdev\n");
        goto add_err;
    }
	//第四步
	/*创建类 */
	class_beep = class_create(THIS_MODULE, DEV_NAME);

	/*创建设备*/
	device = device_create(class_beep, NULL, beep_devno, NULL, DEV_NAME);

	spin_lock_init(&read_lock);  //初始化自旋锁

	return 0;

add_err:
    //添加设备失败时，需要注销设备号
    unregister_chrdev_region(beep_devno, DEV_CNT);
	printk("\n error! \n");
alloc_err:

	return -1;
}

static int beep_remove(struct platform_device *pdv)
{
	device_destroy(class_beep, beep_devno);
	class_destroy(class_beep);
	cdev_del(&beep_chr_dev);
	unregister_chrdev_region(beep_devno, DEV_CNT);
	return 0;
}

static const struct of_device_id beep[] = {
{ .compatible = "beep"},
  { /* sentinel */ }
};

/*定义平台设备结构体*/
struct platform_driver beep_platform_driver = {
	.probe = beep_probe,
	.remove =beep_remove,
	.driver = {
		.name = "beep-platform",
		.owner = THIS_MODULE,
		.of_match_table = beep,
	}
};


/*
*驱动初始化函数
*/
static int __init beep_platform_driver_init(void)
{
	int DriverState;
	
	DriverState = platform_driver_register(&beep_platform_driver);
	
	printk(KERN_EMERG "\tDriverState is %d\n",DriverState);
	return 0;
}

/*
*驱动注销函数
*/
static void __exit beep_platform_driver_exit(void)
{
	printk(KERN_EMERG "BEEP exit!\n");
	
	platform_driver_unregister(&beep_platform_driver);	
}

module_init(beep_platform_driver_init);
module_exit(beep_platform_driver_exit);

MODULE_LICENSE("GPL");

