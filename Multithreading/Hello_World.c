#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char ** argv)
{
    thread1_create();
    printf("main fn paused\n");
    pause();
    return 0;
}