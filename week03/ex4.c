#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){

    static int sum;
    const int *A = (const int*) a, *B = (const int*) b;
    sum = *A + *B;
    return (void*)&sum;

}

void* addDouble(const void* a, const void* b){

    static double sum;
    const double *A = (const double*) a, *B = (const double*) b;
    sum = *A + *B;
    return (void*)&sum;

}

void* mulInt(const void* a, const void* b){

    static int product;
    const int *A = (const int*) a, *B = (const int*) b;
    product = *A * *B;
    return (void*)&product;
    
}

void* mulDouble(const void* a, const void* b){

    static double product;
    const double *A = (const double*) a, *B = (const double*) b;
    product = *A * *B;
    return (void*)&product;

}


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

	void* output = initial_value;

	if (size == sizeof(int)){ // base is a pointer to an integer
	
	    int* arr = (int*) base;

        for(int i = 0; i < n; i++)
        {
            output = opr(output, &arr[i]);
        }
	}else if (size == sizeof(double)) { // base is a pointer to a double
        double* arr = (double*) base;
	    for(int i = 0; i < n; i++)
        {
            output = opr(output, &arr[i]);
        }
	    
	} else {
        return NULL;
    }

	return output;
}


int main(void){

        int* ints = malloc(sizeof(int)*5);
        double* doubles = malloc(sizeof(double)*5);
        
        for(int i = 1; i <= 5; i++)
        {
            ints[i - 1] = i;
            doubles[i - 1] = i / 0.5;
        }


	// Addition
	
        int* result1a;
        
        int initial1a = 0;
        result1a = aggregate(ints, sizeof(int), 5, &initial1a, addInt);
        
        printf("%d\n", *result1a);

	double* result2a;
	
        double initial2a = 0.0;
        result2a = aggregate(doubles, sizeof(double), 5, &initial2a, addDouble);

        printf("%f\n", *result2a);
                

	// Multiplication
	
        int* result1m;
        int initial1m = 1;
        result1m = aggregate(ints, sizeof(int), 5, &initial1m, mulInt);

        
        printf("%d\n", *result1m);

	double* result2m;
	
        double initial2m = 1.0;
        result2m = aggregate(doubles, sizeof(double), 5, &initial2m, mulDouble);

        printf("%f\n", *result2m);
        
        
        
	// Mean
	
        int* result1mean;
        
        int initial1mean = 0;
        result1mean = aggregate(ints, sizeof(int), 5, &initial1mean, addInt);

        printf("%d\n", (*result1mean / 5));

	double* result2mean;
	
        double initial2mean = 0.0;
        result2mean = aggregate(doubles, sizeof(double), 5, &initial2mean, addDouble);

        printf("%f\n", (*result2mean / 5.0));
	
        free(ints);
        free(doubles);

        return 0;
}
