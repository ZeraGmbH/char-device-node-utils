#ifndef CONTROL_NODE_H
#define CONTROL_NODE_H

#include <linux/types.h>
#include <linux/platform_device.h>

int cnc_create_control_node(dev_t first_char_node, struct class *c);
int cnc_destroy_control_node(dev_t first_char_node, struct class *c);

#endif
