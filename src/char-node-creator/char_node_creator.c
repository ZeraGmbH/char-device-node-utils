#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/err.h>
#include <linux/platform_device.h>

#define DEVICE_NAME "char_node_creator"

#define CNC_CLASS_NAME "CharNodeCreator"
static struct class *cnc_class;

static int __init char_node_creator_init(void) {
    cnc_class = class_create(THIS_MODULE, CNC_CLASS_NAME);
    if (IS_ERR(cnc_class)) {
        pr_err("char_node_creator: unable to create class!\n");
        return PTR_ERR(cnc_class);
    }
    printk(KERN_INFO "char_node_creator module loaded\n");
    return 0;
}

static void char_node_creator_exit(void) {
    class_destroy(cnc_class);
    printk(KERN_INFO "char_node_creator module unloaded\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andreas Müller <schnitzeltony@gmail.com>");
MODULE_DESCRIPTION("Dynamic character device node creator");
MODULE_VERSION("0.1");

module_init(char_node_creator_init);
module_exit(char_node_creator_exit);
