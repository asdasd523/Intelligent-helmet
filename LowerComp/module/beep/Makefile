KERNEL_DIR=/home/qigao/qigao/linux_learn/ebf_linux_kernel/build_image/build

ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
export  ARCH  CROSS_COMPILE

obj-m := beep.o

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) modules

.PHONY:clean
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) clean
