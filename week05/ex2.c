#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

struct Thread
{
	int i;
	pthread_t id;
	char message[256];
};

void* display_message(void* arg)
{
	struct Thread *currentThread = arg;
	printf("Id: %lu, %s\n", currentThread->id, currentThread->message);

	return NULL;
}

int main()
{
	int n;
	scanf("%d", &n);
	struct Thread *threads = malloc(n * sizeof(struct Thread));
	if (threads == NULL) {
		return 1;
	}
	for(int i = 0; i < n; i++)
	{
		threads[i].i = i;
		sprintf(threads[i].message, "Hello from thread %d", i);
		printf("Thread %d is created.\n", threads[i].i);
		pthread_create(&threads[i].id, NULL, display_message, threads + i);
		pthread_join(threads[i].id, NULL);
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	pthread_join(threads[i].id, NULL);
	// }

	free(threads);
	return EXIT_SUCCESS;
}