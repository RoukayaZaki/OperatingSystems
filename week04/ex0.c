#include <stdio.h>
#include <unistd.h>
#include <time.h> 

int main(void)
{
    pid_t child_a, child_b;
    clock_t time, t;
    child_a = fork();
    time = clock();
    setvbuf(stdout, NULL, _IONBF, 0);
    if (child_a == 0) {

        printf("Child Process A:\npid :%d\nppid:%d\n",getpid(),getppid());
        t = clock() - time;
        printf ("It took me %lf clicks (%lf seconds).\n", (double)t,((double)t)/CLOCKS_PER_SEC);

    }
    else {
        child_b = fork();
        setvbuf(stdout, NULL, _IONBF, 0);
        time = clock();
        if (child_b == 0) {
            printf("Child Process B:\npid :%d\nppid:%d\n",getpid(),getppid());
            t = clock() - time;
            printf ("It took me %lf clicks (%lf seconds).\n", (double)t,((double)t)/CLOCKS_PER_SEC);
        } else {
            printf("Parent Process:\npid :%d\nppid:%d\n",getpid(),getppid());
            t = clock() - time;
            printf ("It took me %lf clicks (%lf seconds).\n", (double)t,((double)t)/CLOCKS_PER_SEC);
        }
    }
}