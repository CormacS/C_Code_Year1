/*
Program Description: Algorithms lab 6
Author: Cormac Smith
Date: 6/3/2018
*/


#include <stdio.h>
#include <stdlib.h>

//Prototype
void merge(int a[],int low, int mid,int high);
void mergesort(int a[],int low, int high);
//void quicksort(int number[],int first,int last);
void selectionsort(int numbers[],int amount);

int cmpfunc(const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int numbers[1000];
    int i;
    int choice;
    int amount;
    
    printf("How many numbers would you like to enter?\n");
    scanf("%d",&amount);
    
    printf("\nEnter %d numbers randomly\n",amount);
    for(i=0;i<amount;i++)
    {
        scanf("%d",&numbers[i]);
    }
    flushall();
    
    printf("\nWhat sorting method would you like to use?");
    printf("\nPress 1 for Selection Sort");
    printf("\nPress 2 for Merge Sort");
    printf("\nPress 3 for Quick Sort\n");
    scanf("%d",&choice);
    flushall();
    
    switch(choice)
    {
        case 1:
        {
            selectionsort(numbers,amount);
            //Selection Sort

            
            break;

        }
        
        case 2:
        {
            //Calling mergesort
            mergesort(numbers,0,amount-1);
            break;
        }
        
        case 3:
        {
            //Calling quicksort
            qsort(numbers,amount,sizeof(int),cmpfunc);
           
            break;
            
        }
        
        default:
        {
            printf("\nInvalid Entry");
            break;
        }
    }
    
    if(choice == 1 || choice == 2 || choice == 3)
    {
        for(i=0;i<amount;i++)
        {
            printf("%d ",numbers[i]);
        }
    }
    
 getchar();   
 return 0;   
}

//Selection sort
void selectionsort(int numbers[],int amount)
{
    int c,d,position,swap;
    for(c=0;c<(amount-1);c++)
    {
        position = c;
                
        for(d = c + 1;d<amount;d++)
        {
            if(numbers[position]>numbers[d])
            {
                position = d;
            }
        }
                
        if(position != c)
        {
            swap = numbers[c];
            numbers[c] = numbers[position];
            numbers[position] = swap;
        }
    }
}



//merge
void mergesort(int a[], int low, int high)//function to merge sort the array 
{
    if(low < high)
    {
        int m = (high + low)/2;
        mergesort(a,low,m);
        mergesort(a,m+1,high);
        merge(a, low, m, high);
    }
}    

//merge
void merge(int a[], int low, int mid, int high)//function for merging of the array 
{
    int b[10000];
    int i = low, j= mid+1, k=0;
    while(i <= mid && j<= high)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while(i <= mid)
    {
        b[k++] = a[i++];
    }
    while(j <= high)
    {
        b[k++] = a[j++];
    }    
    k--;
    while(k >=0)
    {
        a[low + k] = b[k];
        k--;
    }
    
}

//Quicksort
/*void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}
*/



