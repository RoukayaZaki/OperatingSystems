#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {

    int num_int = INT_MAX;
    printf("%ld\t%d\n", sizeof(num_int), num_int);

    unsigned short int num_unsignedInt = USHRT_MAX;
    printf("%ld\t%d\n", sizeof(num_unsignedInt), num_unsignedInt);

    long int num_longInt = LONG_MAX;
    printf("%ld\t%ld\n", sizeof(num_longInt), num_longInt);

    float num_float = FLT_MAX;
    printf("%ld\t%f\n", sizeof(num_float), num_float);

    double num_double = DBL_MAX;
    printf("%ld\t%lf\n", sizeof(num_double), num_double);

    return 0;
}