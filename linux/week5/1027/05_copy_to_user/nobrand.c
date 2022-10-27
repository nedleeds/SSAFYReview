#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/string.h>

#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");

struct Node {
    char n;
    char buf[100];
};

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
    char buf[30];
    int ret;
    void *p = (void *)(arg);
    struct Node t;

    switch (cmd)
    {
        case _IO(0, 3):
            printk(KERN_INFO "IO 3 - copy_from_user\n");
            ret = copy_from_user((void*) buf, p, 30);
            printk(KERN_ALERT "%s\n", buf);
            break;

        case _IO(0, 4):
            printk(KERN_INFO "IO 4 - copy_to_user\n");
            strcpy(buf, "THIS IS KERNEL MEMORY");
            ret = copy_to_user((void*) arg, (void*) buf, 30);
            break;

        case _IO(0, 5):
            printk(KERN_INFO "IO 5 - copy_from_user - struct\n");
            ret = copy_from_user(&(t.n), (void*)arg, 1);
            ret = copy_from_user(t.buf, (void*)(arg + 1), 100);
            printk(KERN_INFO "%d\n", t.n);
            printk(KERN_INFO "%s\n", t.buf);
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