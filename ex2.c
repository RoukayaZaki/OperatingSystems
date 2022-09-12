#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[256], c;

    int index = 0, isthereadot = 0;
    while((c = getchar()) != EOF) {
        input[index] = c;
        if(input[index] == '.') {
            isthereadot = 1;
            break;
        } 
        index++;
    }

    
    printf("\"");

    int flag = 0;

    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        if(flag || isthereadot == 0) {
            printf("%c", input[i]);
        }
        else if(input[i] == '.') {
                flag = 1;
        }
    }
    printf("\"\n");

    return 0;
}