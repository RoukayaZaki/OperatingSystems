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
	char *line = "------------------------";

	printf("%s\n|          Memory Usage|\n%s\n", line, line);
	for(int i = 0; i < 10; i++)
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

		printf("| %20ld |\n", usage.ru_maxrss);
		
		sleep(1);
	}
    
	printf("%s\n", line);

    for(int i = 0; i < 10; i++)
	    free(data[i]);
	
	return 0;
}