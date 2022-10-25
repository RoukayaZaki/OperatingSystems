#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void *ptr, size_t size)
{
	if(size == 0)
	{
		free(ptr);
		return NULL;
	}
	
	if(ptr == NULL)
		return malloc(size);
	
	void *new_ptr = malloc(size);
	if(new_ptr == NULL)
		return NULL;
	
	memcpy(new_ptr, ptr, size);

	free(ptr);
	return new_ptr;
}

void print_array(int *arr, int size)
{
	if(arr == NULL)
		return;

	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int size = 5;
    // Allocate memory
	printf("Allocating space for %d ints\n", size);
	int *arr = (int*)my_realloc(NULL, size * sizeof(int));

	for(int i = 0; i < size; i++)
		arr[i] = i;
	printf("Array content:\n");
	print_array(arr, size);
	
	// Increase size
	size = 10;
	printf("\nResizing to be %d ints long:\n", size);
	arr = (int*)my_realloc(arr, size * sizeof(int));
	printf("New array content:\n");
	print_array(arr, size);

	// Decrease size
	size = 2;
	printf("\nResizing to be %d ints long:\n", size);
	arr = (int*)my_realloc(arr, size * sizeof(int));
	printf("New array content:\n");
	print_array(arr, size);
	
	// Free the array
	printf("\nFreeing the array:\n");
	arr = (int*)my_realloc(arr, 0);
	printf("Pointer after freeing: %p\n", arr);
	
	return 0;
}