#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_multiply(long a, long b) {
	return a * b;
}
