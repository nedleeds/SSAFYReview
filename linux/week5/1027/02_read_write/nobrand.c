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

static ssize_t nobrand_read(struct file *filp, char *buf, size_t count, loff_t *ppos)
{
    buf[0] = 'H';
    buf[1] = 'I';
    buf[2] = '\0';
    return count;
}

static ssize_t nobrand_write(struct file *filp, const char*buf, size_t count, loff_t *ppos)
{
    printk(KERN_INFO "app message: %s\n", buf);
    return count;
}

static struct file_operations fops = {
    .open = nobrand_open,
    .release = nobrand_release,
    .read = nobrand_read,
    .write = nobrand_write,
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
