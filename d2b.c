#include <stdio.h>
/*
This program turns decimal to binary
Author: Cormac Smith
*/


int main()
{
    int decimal;
    int i = 1;
    int result;
    int counter;
    
    int binary[100]; //used for storing the 1s and 0s
    
    printf("Enter a number\n");
    scanf("%d", &decimal);
    flushall();
    
    result = decimal;
    
    
    while(result != 0)
    {
        binary[i++] = result % 2; // Finds the remainder of %2, then adds it to the array
        result = result /2; //Divides the number used by 2, then uses that number to find next part
    }
    
    printf("\nDecimal Entered: %d\n",decimal);
    printf("Binary value: ");
    for (counter = i - 1;counter > 0; counter--) //Start from the top andn decrement because u read backwards   
    {
        printf("%d",binary[counter]);
    }
    
    getchar();
    return 0;
    
}