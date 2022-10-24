KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build

obj-m := 01_device_driver_module.o

go:
	make -C $(KERNEL_HEADERS) M=$(PWD) modules

clean:
	make -C $(KERNEL_HEADERS) M=$(PWD) clean
