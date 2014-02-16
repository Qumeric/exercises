#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * 9.0/5.0 + 32;
        printf("%7.0f\t%10.0f\n", celsius, fahr);
        celsius += step;
    }
}
