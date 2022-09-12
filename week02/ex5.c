#include <stdio.h>

int tribonacci(int n) {
    int first = 0, second = 1, third = 1, current = 0;

    if(n < 2) return n;
    if(n == 2) return 1;

    for(int i = 3; i <= n; i++) {
        current = first + second + third;
        first = second;
        second = third;
        third = current;
    }

    return current;
}

int main(void) {
    int n;

    scanf("%d", &n);

    printf("%d\n", tribonacci(n));
}