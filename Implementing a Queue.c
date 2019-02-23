#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void push1(char);
void push2(char);
int pop1();
int pop2();
void enqueue(char);
void dequeue();
void display();
void create();
 
char st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
 
void main()
{

    int i;
    int length;
    char array[100];
    
    printf("Enter your string,use * to pop\n");
    scanf("%s",&array);
    flushall();
    
    length = strlen(array);
    
    create();
    
    for(i=0;i<length;i++)
    {
        if(array[i] == '*')
        {
            dequeue();
        }
        else
        {
            enqueue(array[i]);
        }
    }
    
    display();

    getchar();
    
}
 
/*Function to create a queue*/
void create()
{
    top1 = top2 = -1;
}
 
/*Function to push the element on to the stack*/
void push1(char data)
{
    st1[++top1] = data;
}
 
/*Function to pop the element from the stack*/
int pop1()
{
    return(st1[top1--]);
}
 
/*Function to push an element on to stack*/
void push2(char array)
{
    st2[++top2] = array;
}
 
/*Function to pop an element from th stack*/
 
int pop2()
{
    return(st2[top2--]);
}
 
/*Function to add an element into the queue using stack*/
void enqueue(char array)
{

    push1(array);
    count++;
}
 
/*Function to delete an element from the queue using stack*/
 
void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}
 
/*Function to display the elements in the stack*/
 
void display()
{
    int i;
 
    for (i = 0;i <= top1;i++)
    {
        printf(" %c ", st1[i]);
    }
}