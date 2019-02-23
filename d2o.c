#include <stdio.h>
/*
This program turns decimal to octal
Author: Cormac Smith
*/


int main()
{
    int decimal;
    int i = 1;
    int result;
    int counter;
    
    int octal[100];
    
    printf("Enter a number\n");
    scanf("%d", &decimal);
    flushall();
    
    result = decimal;
    
    
    while(result != 0)
    {
        octal[i++] = result % 8;
        result = result /8;
    }
    
    printf("\nDecimal Entered: %d\n",decimal);
    printf("Octal value: ");
    for (counter = i - 1;counter > 0; counter--)
    {
        printf("%d",octal[counter]);
    }
    
    getchar();
    return 0;
    
}