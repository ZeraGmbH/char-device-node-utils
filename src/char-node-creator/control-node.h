#ifndef CONTROL_NODE_H
#define CONTROL_NODE_H

#include <linux/types.h>
#include <linux/platform_device.h>

int cnc_control_create_node(dev_t first_char_node, struct class *c);
int cnc_control_destroy_node(dev_t first_char_node, struct class *c);

#endif
