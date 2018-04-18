#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_min(long a, long b) {
	return a > b? b: a;
}
