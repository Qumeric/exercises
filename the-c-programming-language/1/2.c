#include <stdio.h>

int main(void)
{
    printf("\a"); // Alarm

    printf("Sample input:\n");
    printf("This is test<escape sequence>just a test!\n\n");

    printf("Carriage return (\\r):\n");
    printf("This is test\rjust a test!\n\n");
    
    printf("Vertical tab (\\v):\n");
    printf("This is test\vjust a test!\n");
}
