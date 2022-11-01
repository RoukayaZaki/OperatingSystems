#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	int *data[10] = {NULL};
    const int MB = 1024 * 1024;

	size_t size = 0;
	struct rusage usage;
	char *div = "----------------------------------------------------------"
				"---------------------------------------------------------";

	printf("%s\n", div);
	printf("| User CPU time (usec) | System CPU time (usec) | Page faults"
		   " (w/o I/O) | Page faults (w/ I/O) | Context switches |\n");
	printf("%s\n", div);
	for(int i=0; i<10; i++)
	{
		size += 10 * MB;
		data[i] = malloc(size);

		if(data[i] == NULL)
		{
			printf("Warning: out of memory!\n");
			return 1;
		}

		memset(data[i], 0, size);
		
		getrusage(RUSAGE_SELF, &usage);
		printf("| %20ld | %22ld | %21ld | %20ld | %16ld |\n",
			usage.ru_utime.tv_usec,
			usage.ru_stime.tv_usec,
			usage.ru_minflt,
			usage.ru_majflt,
			usage.ru_nvcsw + usage.ru_nivcsw
		);
		
		sleep(1);
	}
	printf("%s\n", div);

    for(int i = 0; i < 10; i++)
	    free(data[i]);
	
	return 0;
}