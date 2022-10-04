#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    mkfifo("/tmp/ex1", 0777);
    int fd = open("/tmp/ex1", O_WRONLY);
    if (fd == -1) {
        return 1;
    }

    
    while(1)
    {
        char message[1024] = "";
        fgets(message, 1024, stdin);
        for (int i = 0; i < n; i++){
            if((write(fd, message, sizeof(char) * strlen(message))) == -1) {
                return 1;
            }
            sleep(1);
        }
    }

    close(fd);
}