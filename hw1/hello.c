#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage int sys_hello(void) {
	printk("HELLO SYSTEM CALL B05202043 \n");
	return 0;
}
