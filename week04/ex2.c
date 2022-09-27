#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 120

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;
	
	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}
	
	return result;
}


int main(){


	int u[SIZE], v[SIZE], n;

	for(int i = 0; i < SIZE; i++) {
		u[i] = rand() % 100;
		v[i] = rand() % 100;
	}
	FILE* temp = fopen("temp.txt", "w+");

	scanf("%d", &n);
	int range = SIZE / n;
	for(int i = 0; i < n; i++)
	{
		pid_t pid = fork();
		if(pid == 0) {
			fprintf(temp, "%d ", dotprod(u, v, range * i, range *(i + 1)));
			fflush(temp);
			return 0;
		}
	}
	fseek(temp, 0, 0);
	
	int result = 0, prod;
	for(int i = 0; i < n; i++){
		fscanf(temp, "%d ", &prod);
		result += prod;
	}

	// fprintf(temp, "The result of the dot-product: %d\n", result);
	printf("The result of the dot-product: %d\n", result);

	return 0;

}