#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd[2];
    // fd[0] - read end
    // fd[1] - write end
    if(pipe(fd) == -1) { 
        printf("Error");
        return 1;
    };

    int publisher = fork();

    if (publisher == 0)
    {
        close(fd[0]);
        while(1)
        {

            char message[256];
            scanf("%s", message);

            write(fd[1], message, sizeof(message));
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        while(1)
        {

            char recieved_message[256] = "";

            read(fd[0], recieved_message, sizeof(recieved_message));
            //close(fd[0]);

            printf("%s\n", recieved_message);
        }
    }

    return 0;
}



// pipe reference 
// https://man7.org/linux/man-pages/man2/pipe.2.html