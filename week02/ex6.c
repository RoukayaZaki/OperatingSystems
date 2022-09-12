#include <stdio.h>

void pattern1(int n) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

}

void pattern2(int n) {

    int mid = n / 2 + (n % 2);

    pattern1(mid);

    if(n % 2 == 1) mid--;

    for(int i = mid; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void pattern3(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pattern1(n);
    pattern2(n);
    pattern3(n);
}