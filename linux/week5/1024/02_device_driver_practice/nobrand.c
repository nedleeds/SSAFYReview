#include <linux/module.h>
#include <linux/fs.h>

#define NOD_MAJOR 100
#define NOD_NAME "nobrand" 

MODULE_LICENSE("GPL");

static int nobrand_open(struct inode *inode, struct file *filp){
	printk( KERN_INFO "welcome\n");
	return 0;
}

static int nobrand_release(struct inode *inode, struct file *filp){
	printk( KERN_INFO "release\n");
	return 0;
}

static struct file_operations fops = {
	.open = nobrand_open,
	.release = nobrand_release,
};

static int nobrand_init(void){
	// init을 할 때 device driver를 연결한다
	if (register_chrdev(NOD_MAJOR, NOD_NAME, &fops)<0){
		printk(KERN_INFO "INIT FAIL\n");	
	}
	printk(KERN_INFO "hi\n");
	return 0;
}

static void nobrand_exit(void){
	unregister_chrdev(NOD_MAJOR, NOD_NAME);
	printk(KERN_INFO "bye\n");
}


module_init(nobrand_init);
module_exit(nobrand_exit);
