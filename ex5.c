#include <stdio.h>
#include <string.h>

int tribonacci(int n);

int tribonacci(int n) {
    int num1 = 0;
    int num2 = 1;
    int num3 = 1;
    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            curr = num1;
        }
        else if(i == 1) {
            curr = num2;
        }
        else if(i == 2) {
            curr = num3;
        }
        else {
            curr = num3 + num2 + num1;
        }
        num1 = num2;
        num2 = num3;
        num3 = curr;
    }

    return curr;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("%d\n", tribonacci(n));
}