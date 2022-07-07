obj-m += char_node_creator.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	-sudo rmmod char_node_creator
	sudo insmod char_node_creator.ko
	lsmod | grep char_node_creator
