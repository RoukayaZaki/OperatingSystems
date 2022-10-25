#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	
	while(n <= 0)
	{
		printf("Please enter a positive number: ");
		scanf("%d", &n);
	}
	
	int *numbers = (int*)malloc(n * sizeof(int));
	
	if(numbers == NULL)
	{
		printf("An error occured allocating memory!\n");
		return 1;
	}
	
	printf("Array contents:\n");
	for(int i = 0; i < n; i++)
    {
		numbers[i] = i;
		printf("%d ", numbers[i]);
    }
	printf("\n");
    
	free(numbers);
	
	return 0;
}