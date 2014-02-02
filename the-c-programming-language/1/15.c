#include <stdio.h>

float fahr2celsius(float);

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    printf("Fahrenheit\tCelsius\n");

    fahr = lower;
    while (fahr <= upper) {
        printf("%10.0f\t%7.1f\n", fahr, fahr2celsius(fahr));
        fahr = fahr + step;
    }
}

float fahr2celsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
