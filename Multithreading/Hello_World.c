#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void thread1_create()
{
    pthread_t pthread1;

    static char *thread_input1 = "I am thread no 1";
}

int main(int argc, char ** argv)
{
    thread1_create();
    printf("main fn paused\n");
    pause();
    return 0;
}