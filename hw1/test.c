#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main() {
    long a, b;
    printf("Input two long: ");    
    scanf("%ld %ld", &a, &b);
    syscall(337);
    printf("multiply a, b = %ld", syscall(338, a, b));
    printf("\nmin a, b = %ld", syscall(339, a, b));
    printf("\n");
    return 0;
}
