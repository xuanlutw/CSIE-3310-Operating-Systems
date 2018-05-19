#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

void* thread(void* num) {
    for (int i = 0;i < 3;++i) {
        printf("Thread %d is running.\n", (int)num);
        sleep(5);
        //for (int j = 0;j < 1000000000;++j);
    }
    return NULL;
}

int main(int argv, char** argc) {
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0, &mask);
    if (sched_setaffinity(0, sizeof(mask), &mask) == -1)
        printf("set affinity err\n");

    if ((argv == 2) && !strcmp(argc[1], "SCHED_FIFO")) {
        struct sched_param param;
        int maxpri;
        if ((maxpri = sched_get_priority_max(SCHED_FIFO)) == -1)
            printf("get priority err\n");
        param.sched_priority = maxpri;
        if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1)
            printf("set FIFO err\n");
    }

    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    for (int i = 0;i < 2;++i) 
        pthread_create(tid + i, &attr, thread, (void*)(i + 1));
    for (int i = 0;i < 2;++i)
        pthread_join(tid[i], NULL);
    return 0;
}
