
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>


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
#include <linux/irq.h>
#include <linux/of_irq.h>

#include <linux/types.h>

/*------------------字符设备内容----------------------*/
#define DEV_NAME "MQ135"
#define DEV_CNT (1)

static dev_t MQ135_devno;        //字符设备号
static struct cdev MQ135_chr_dev; //字符设备结构体chr_dev
struct class *class_MQ135;  	 //保存创建的类
struct device* device_MQ135;     //保存创建的设备

struct device_node * MQ135_device_node = NULL;  //定义设备的节点结构体
unsigned MQ135_GPIO_number = 0; 				//MQ135使用的GPIO引脚编号
u32 interrupt_number = 0;  						//引脚中断编号
atomic_t  MQ135_status = ATOMIC_INIT(0);		//定义整型原子变量，保存中断状态 ，设置初始值为0


static irqreturn_t MQ135_irq_handler(int irq,void *dev_id)
{
	atomic_inc(&MQ135_status);
	return IRQ_HANDLED;
}

static int MQ135_open(struct inode *inode, struct file *filp)
{
	int error = -1;

	/*获取MQ135设备树节点*/
	MQ135_device_node = of_find_node_by_path("/MQ135_interrupt");
	if(NULL == MQ135_device_node)
	{
		printk("of_find_node_by_path error!");
		return -1;
	}

	/*获取按键使用的GPIO*/
	MQ135_GPIO_number = of_get_named_gpio(MQ135_device_node ,"MQ135_gpio", 0);
	if(0 == MQ135_GPIO_number)
	{
		printk("of_get_named_gpio error");
		return -1;
	}

	/*申请GPIO*/
	error = gpio_request(MQ135_GPIO_number, "MQ135_gpio");
	if(error < 0)
	{
		printk("gpio_request error");
		gpio_free(MQ135_GPIO_number);
		return -1;
	}

	error = gpio_direction_input(MQ135_GPIO_number);//设置引脚为输入模式

	/*获取中断号*/
	interrupt_number = irq_of_parse_and_map(MQ135_device_node, 0);
	printk("\n irq_of_parse_and_map! =  %d \n",interrupt_number);

	/*申请中断*/
	error = request_irq(interrupt_number,MQ135_irq_handler,IRQF_TRIGGER_RISING,"MQ135_interrupt",device_MQ135);
	if(error != 0){
		printk("request_irq error");
		free_irq(interrupt_number, device_MQ135);
		return -1;
	}

	/*申请之后中断已经开启了，切记不要再次打开，否则运行时报错*/
	// // enable_irq(interrupt_number);

	return 0;
}


static int MQ135_read(struct file *filp, char __user *buf, size_t cnt, loff_t *offt)
{
	int error = -1;
	int MQ135_countervc = 0;

	/*读取MQ135状态值*/
	MQ135_countervc = atomic_read(&MQ135_status);

	/*结果拷贝到用户空间*/
	error = copy_to_user(buf, &MQ135_countervc, sizeof(MQ135_countervc));
	if(error < 0)
	{
		printk("copy_to_user error");
		return -1;
	}

	/*清零按键状态值*/
	atomic_set(&MQ135_status,0);
	return 0;
}

/*字符设备操作函数集，.release函数实现*/
static int MQ135_release(struct inode *inode, struct file *filp)
{
	/*释放申请的引脚,和中断*/
	gpio_free(MQ135_GPIO_number);
	free_irq(interrupt_number, device_MQ135);
	return 0;
}

/*字符设备操作函数集*/
static struct file_operations MQ135_chr_dev_fops = {
	.owner = THIS_MODULE,
	.open = MQ135_open,
	.read = MQ135_read,
	.release = MQ135_release,
};


/*驱动初始化函数*/
static int __init MQ135_init(void)
{
	int error = -1;

	/*采用动态分配的方式，获取设备编号，次设备号为0，*/
	error = alloc_chrdev_region(&MQ135_devno, 0, DEV_CNT, DEV_NAME);
	if (error < 0)
	{
		printk("fail to alloc button_devno\n");
		goto alloc_err;
	}

	/*关联字符设备结构体cdev与文件操作结构体file_operations*/
	MQ135_chr_dev.owner = THIS_MODULE;
	cdev_init(&MQ135_chr_dev, &MQ135_chr_dev_fops);

	/*添加设备至cdev_map散列表中*/ 
	error = cdev_add(&MQ135_chr_dev, MQ135_devno, DEV_CNT);
	if (error < 0) 
	{
		printk("fail to add cdev\n");
		goto add_err;
	}

	class_MQ135 = class_create(THIS_MODULE, DEV_NAME); //创建类
	device_MQ135 = device_create(class_MQ135, NULL, MQ135_devno, NULL, DEV_NAME);//创建设备 DEV_NAME 指定设备名，

	//printk("MQ135 driver init successfully \n");


	return 0;

add_err:
	unregister_chrdev_region(MQ135_devno, DEV_CNT);    // 添加设备失败时，需要注销设备号
	printk("\n error! \n");

alloc_err:
	return -1;
}

/*
*驱动注销函数
*/

static void __exit MQ135_exit(void)
{
	pr_info("MQ135_exit\n");
	/*删除设备*/
	device_destroy(class_MQ135, MQ135_devno);		  //清除设备
	class_destroy(class_MQ135);					   	  //清除类
	cdev_del(&MQ135_chr_dev);					      //清除设备号
	unregister_chrdev_region(MQ135_devno, DEV_CNT);   //取消注册字符设备
}

module_init(MQ135_init);
module_exit(MQ135_exit);


MODULE_LICENSE("GPL");




