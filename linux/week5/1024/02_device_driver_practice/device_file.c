#include <linux/module.h>

static int nobrand_init(void){
	printk( KERN_INFO "hi\n" );
	return 0;
}

static void nobrand_exit(void){
	printk( KERN_INFO "bye\n");
}

module_init(nobrand_init);
module_exit(nobrand_exit);
