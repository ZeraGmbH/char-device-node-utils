obj-m += char_node_creator.o
char_node_creator-objs := char-node-creator.o control-node.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

