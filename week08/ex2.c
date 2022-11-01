/*
ex2
The si and so fields indicate whether the systems physical memory
is full and the swap partition/file is being used. Since these
values are zeros in my case that means that the physical memory
isn't full and therefore didn't use swaps.
*/
/*
ex3
The memory used by the program inceased every 2-3 seconds.
The number of processes decrease by 1 after the program is finished.
The memory available decreases each second and after the program is
finished it increases again.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int *data[10] = {NULL};
    const int megabyte = 1024 * 1024;
    
	size_t size = 0;
	for(int i = 0; i < 10; i++)
	{
		size = 10 * megabyte;
		data[i] = malloc(size);
		if(data[i] == NULL)
		{
			printf("Warning: out of memory!\n");
			return 1;
		}
		memset(data[i], 0, size);
		sleep(1);
	}
	
    for(int i = 0; i < 10; i++)
		free(data[i]);
	
	return 0;
}