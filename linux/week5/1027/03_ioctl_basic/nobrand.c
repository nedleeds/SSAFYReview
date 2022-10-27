#include <linux/module.h>
#include <linux/fs.h>

#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");

static int nobrand_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "welcome\n");
    return 0;
}

static int nobrand_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "release\n");
    return 0;
}

/*--------------- ioctl custom ---------------*/
static long nobrand_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    switch (cmd)
    {
        case _IO(0, 3):
            printk(KERN_ALERT "HI ioctl 3 - arg : %lu\n", arg);
            break;
        case _IO(0, 4):
            printk(KERN_ALERT "HI ioctl 4 - arg : %lu\n", arg);
            break;
        case _IO(0, 5):
            printk(KERN_ALERT "HI ioctl 5 - arg : %lu\n", arg);
            break;
    }
    return 0;
}
/*----------------------------------------------*/

static struct file_operations fops = {
    .open = nobrand_open,
    .release = nobrand_release,
    .unlocked_ioctl = nobrand_ioctl, // for utilizing "ioctl"
};

static int nobrand_init(void)
{
    if (register_chrdev(NOD_MAJOR, NOD_NAME, &fops) < 0)
    {
        printk("INIT FALE\n");
    }

    printk(KERN_INFO "hi\n");
    return 0;
}

static void nobrand_exit(void)
{
    unregister_chrdev(NOD_MAJOR, NOD_NAME);
    printk(KERN_INFO "bye\n");
}

module_init(nobrand_init);
module_exit(nobrand_exit);