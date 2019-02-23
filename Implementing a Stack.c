#include <stdio.h>
#include <string.h>
#define SIZE 100
//char array[24] = {'E','A','S','*','Y','Q','U','E','*','*','*','S','T','*','*','*','I','O','*','N','*','*','*'};
char array[SIZE];
int top = -1;
void push(char);
void pop();

int main()
{
    int i;
    int length;
    printf("Enter your string,use * to pop\n");
    scanf("%s",&array);
    flushall();
    
    length = strlen(array);
    
    printf("\n");
    for(i=0;i<length;i++)
    {
        
        if(array[i] == '*')
        {
            pop();
        }
        else
        {
            push(array[i]);
        }

    }
    printf("\n");
    printf("Stack: ");
    for(i=0;i<=top;i++)
    {
        printf("%c ",array[i]);
    }
    
    getchar();
    return 0;
}

void push(char x) 
{

	array[++top] = x;
}

void pop() 
{
	top--;
}