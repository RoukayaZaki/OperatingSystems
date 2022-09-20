#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(const int age) {
   return 2022 - age; 
}   

int main(void) {
    const int x = 10;

    const int* q = &x;

    const int* const p = (int *)malloc(5*sizeof(int));

    for(int i = 0; i < 5; i++) {
        int* value = (int *) (p+i);
        *value = x;
    }

    printf("Enter the ages:\n");

    for(int i = 0; i < 5; i++) {
        int age;
        scanf("%d", &age);

        int* cellValue = (int *)(p+i);
        *cellValue = age;
    }
    for(int i = 0; i < 5; i++) {
        
        int* birthyear = (int*)(p + i);
        *birthyear = foo(*birthyear);

    }

    for(int i = 0; i < 5; i++) {
        printf("Birthyear of %d: %d\n", (i+1), *(p+i));
    }

    free((int *)p);

    return 0;

}