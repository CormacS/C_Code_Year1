#include <stdio.h>
 
int main()
{
    int decimal;
    int result;
    int remainder;
    int i;
    int counter = 0;
    char hexadecimal[100];
 
    printf("Enter decimal number: ");
    scanf("%ld", &decimal);
    flushall();
 
    result = decimal;
 
    while (result != 0)
    {
        remainder = result % 16;
        if (remainder < 10)
        {
            hexadecimal[counter++] = 48 + remainder;
        }
        else
        {
            hexadecimal[counter++] = 55 + remainder;
        }
        result = result / 16;
    }
 
    
    for (i = counter; i >= 0; i--)
            printf("%c", hexadecimal[i]);
    
    getchar();
    return 0;
}
