#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    mkfifo("/tmp/ex1", 0777);
    int fd = open("/tmp/ex1", O_RDONLY);

    if (fd == -1) {
        return 1;
    }

    while(1)
    {
        char message[1024] = "";
        if(read(fd, message, 1024) == -1) {
            return 1;
        }
        printf("%s", message);
        fflush(stdout);
    }

    close(fd);
}