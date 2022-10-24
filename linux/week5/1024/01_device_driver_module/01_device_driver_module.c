#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("will");
MODULE_DESCRIPTION("My first device driver");

//kernel의 함수는 static 을 적용해야한다
static int hi_init(void){
	printk( KERN_INFO "OK HELLO KFC\n");
	return 0;// init은 return 값이 필요하다
}

static void hi_exit(void){
	printk( KERN_INFO "BYE BYE\n\n");
}

module_init(hi_init);
module_exit(hi_exit);
