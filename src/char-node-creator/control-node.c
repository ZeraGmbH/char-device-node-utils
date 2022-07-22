#include "control-node.h"
#include "globals.h"
#include <linux/cdev.h>
#include <linux/fs.h>

static ssize_t cnc_control_read(struct file *f, char __user *u, size_t s, loff_t *o)
{
    return 0;
}

static ssize_t cnc_control_write(struct file *f, const char __user *u, size_t s, loff_t *o)
{
    return 0;
}

static int cnc_control_open(struct inode *i, struct file *f)
{
    return 0;
}

static int cnc_control_release(struct inode *i, struct file *f)
{
    return 0;
}

struct cdev cnc_cdev;
struct device *cnc_device = NULL;

struct file_operations cnc_fops = {
    .read =  cnc_control_read,
    .write = cnc_control_write,
    .open =  cnc_control_open,
    .release =  cnc_control_release
};


int cnc_create_control_node(dev_t first_char_node, struct class *c)
{
    int ret;

    cdev_init(&cnc_cdev, &cnc_fops);
    cnc_cdev.owner = THIS_MODULE;
    ret = cdev_add(&cnc_cdev, first_char_node, 1);
    if (ret == 0) {
        cnc_device = device_create(c, NULL, first_char_node, NULL, "%s", CNC_NAME);
        if (IS_ERR(cnc_device)) {
            ret = PTR_ERR(cnc_device);
        }
    }
    else {
        cdev_del(&cnc_cdev);
    }
    return ret;
}

int cnc_destroy_control_node(dev_t first_char_node, struct class *c)
{
    device_destroy(c, first_char_node);
    cdev_del(&cnc_cdev);
    return 0;
}
