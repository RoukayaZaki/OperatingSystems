#include <stdio.h>
#include <unistd.h>
#include <time.h> 
#include <sys/types.h>
#include <signal.h>

int main(void)
{
    pid_t child_a, child_b;
    clock_t time, t;
    child_a = fork();
    time = clock();
    if (child_a == 0) {

        t = clock() - time;
        printf("Child Process A:\tpid :%d\tppid:%d\tIt took me %lf clicks (%lf seconds).\n",getpid(),getppid(), (double)t,((double)t)/CLOCKS_PER_SEC);
    }
    else {
        child_b = fork();
        time = clock();
        if (child_b == 0) {
            t = clock() - time;
            printf("Child Process B:\tpid :%d\tppid:%d\tIt took me %lf clicks (%lf seconds).\n",getpid(),getppid(), (double)t,((double)t)/CLOCKS_PER_SEC);

        } else {
            t = clock() - time;
            printf("Parent Process:\tpid :%d\tppid:%d\tIt took me %lf clicks (%lf seconds).\n",getpid(),getppid(), (double)t,((double)t)/CLOCKS_PER_SEC);
        }
    }
}