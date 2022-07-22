#include "control-node.h"
#include "globals.h"
#include <linux/module.h>
#include <linux/platform_device.h>
#include "linux/fs.h"

#define CNC_CLASS_NAME "CharNodeCreator"
static struct class *cnc_class;
static dev_t first_char_node;
static int node_count = 1;  /* TODO module param */

static int __init char_node_creator_init(void)
{
    int ret;
    cnc_class = class_create(THIS_MODULE, CNC_CLASS_NAME);
    if (IS_ERR(cnc_class)) {
        pr_err("char_node_creator: unable to create class!\n");
        return PTR_ERR(cnc_class);
    }
    ret = alloc_chrdev_region (
                    &first_char_node,
                    0,
                    node_count,
                    CNC_NAME);
    if (ret) {
        pr_err("char_node_creator: unable to alloc_chrdev_region!\n");
        return ret;
    }

    ret = cnc_create_control_node(first_char_node, cnc_class);
    if (ret) {
        unregister_chrdev_region(first_char_node, node_count);
        class_destroy(cnc_class);
        pr_err("char_node_creator: cnc_create_control_node failed!\n");
        return ret;
    }
    printk(KERN_INFO "char_node_creator module loaded\n");
    return 0;
}

static void __exit char_node_creator_exit(void)
{
    cnc_destroy_control_node(first_char_node, cnc_class);
    unregister_chrdev_region(first_char_node, node_count);
    class_destroy(cnc_class);
    printk(KERN_INFO "char_node_creator module unloaded\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andreas Müller <schnitzeltony@gmail.com>");
MODULE_DESCRIPTION("Dynamic character device node creator");
MODULE_VERSION("0.1");

module_init(char_node_creator_init);
module_exit(char_node_creator_exit);
