#include <stdio.h>
#include <string.h>

long long int convertToDecimal(long long int num, long long int base)
{
    long long int result = 0, multiplier = 1;

    while (num != 0)
    {
        long long int lastdigit = num % 10;
        result += lastdigit * multiplier;
        num /= 10;
        multiplier *= base;
    }
    return result;
}

void convert(long long int num, int source, int target)
{

    long long int decimalValue = convertToDecimal(num, source);

    char result[256];
    int index = 0;

    while (decimalValue != 0)
    {
        long long int lastdigit = decimalValue % target;
        result[index] = lastdigit + '0';
        index++;
        decimalValue /= target;
    }

    for(int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main(void)
{
    long long int x;
    int s,;

    scanf("%lld %d %d", &x, &s, &t);

    convert(x, s, t);
}