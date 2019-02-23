/* Program Description: This program is a lotto game, where the user can enter 6 numbers, display the contents,
Sort the 6 numbres entered and compare the numbers entered with the winning numbers. The code is modularised
which means that all the tasks are carried out in sepera4te functions.
Author: Cormac Smith
Date of Submission: March 11th 2018             
*/

// *(variablename + i)

#include <stdio.h>
//Used for clear screen function
#include <conio.h>
#include <stdlib.h>
#define SIZE 6
#define ALLNUMS 43


//Prototypes
void enternumbers(int[],int[]); 
void displaycontents(int[]); 
void sortarray(int[]);
void comparearray(int[]);
void frequency(int[]);
int leave(int);



int main()
{
    
    int done = 0;
    int exit = 0;
    int usernumbers[SIZE];
    int allnumbers[ALLNUMS] = {0,};
    printf("Welcome to the Lotto Game!\n");
    
    //do while used for menu
    do
    {
        int choice = 0;
        
        printf("\nPress 1 to Enter your 6 numbers for the Lotto\n");
        printf("Press 2 to Display the numbers you entered\n");
        printf("Press 3 to Sort the numbers you entered\n");
        printf("Press 4 to Check if your numbers are winning numbers\n");
        printf("Press 5 to Display the frequency of the numbers entered\n");
        printf("Press 6 to Exit\n");
        
        scanf("%d",&choice);
        flushall();
        clrscr();
        
        //This switch checks what option the user choice and goes into that case.
        switch(choice)
        {
            case 1:
            {
                //Calling function for option 1
                enternumbers(usernumbers,allnumbers);
                
                //Used to show that option 1 has been done
                done++;
                break;
            }//end case 1
            
            case 2:
            {
                //This makes sure option 1 has been done first
                if(done == 0)
                {
                    printf("\nYou need to do part 1 first!\n");
                    
                }
                else
                {
                    //calling function for option 2
                    displaycontents(usernumbers);
                    
                }//end if else
                
                break;
            }//end case 2
            
            case 3:
            {   
                //This makes sure option 1 has been done first
                if(done == 0)
                {
                    printf("\nYou need to do part 1 first!\n");
                }
                else
                {
                    //Calling function for option 3
                    sortarray(usernumbers);
                }//end if else
                
                break;
            }//end case 3
            
            case 4:
            {
                //This makes sure option 1 has been done first
                if(done == 0)
                {
                    printf("\nYou need to do part 1 first!\n");
                }
                else
                {
                    //Calling function for option 4
                    comparearray(usernumbers);
                }//end if else
                
                break;
            }//end case 4
            
            case 5:
            {
                //This makes sure option 1 has been done first
                if(done == 0)
                {
                    printf("\nYou need to do part 1 first!\n");
                }
                else
                {
                    //Calling function for option 5
                    frequency(allnumbers);
                }//end if else
                break;
            }//end case 5
            
            case 6:
            {
                //Calling function for option 6 and passing back a variable used to exit the do while loop
                exit= leave(exit);
                break;
            }//end case 6
            
            // used if user inputs invalid integers
            default:
            {
                printf("\nInvalid Entry\n");
            }//end default
            
        }//end switch
                
        
    }//end do while
    while(exit == 0);
        
    getchar();
    return 0;
    
}//end function

//Option 1
void enternumbers(int usernumbers[],int allnumbers[])
{
    int i;
    int j;
    int temp[SIZE];
    int counter = 0;
    
    //while loop used to allow user to keep entering a set of numbers until a set is valid
    while(counter == 0)
    {
        int error = 0;
        printf("\nPlease enter your 6 numbers\n");
        //for loop for entering numbers
        for(i=0;i<SIZE;i++)
        {
            scanf("%d",&temp[i]);

        }//end for
        flushall();
        
        //Used to error check the numbers entered
        for(i=0;i<SIZE;i++)
        {
            //Used to check if any of the entered numbers are the same
            for(j=i+1;j<SIZE;j++)
            {
                //if statement used to increase error counter if any numbers are the same
                if(*(temp+i) == *(temp+j))
                {
                    error++;
                }//end if 
            }// end for
            
            //Used to check if numbers are between 1 and 42
            if(*(temp+i) < 1 || *(temp + i) > 42)
            {
                error++;
            }//end if
        }//end for
        
        //If else statement used to either tell user to enter new numbers or continue if they are valid
        if(error == 0)
        {
            counter++;
            int temp2;
            //for loop used to move numbers from temp array to the desired arry
            for(i=0;i<SIZE;i++)
            {
                temp2 = *(temp+i);
                *(allnumbers+temp2)= *(allnumbers+temp2)+1;
                *(usernumbers+i) = temp2;
            }//end for
        }
        else
        {
            printf("\nInvalid numbers entered\n");
            
        }//end if else
    }//end while
    system("CLS");  
}//end function

//Option 2
void displaycontents(int usernumbers[])
{
    int i;
    printf("\nThe number entered were: ");
    
    //For loop used to display numbers
    for(i=0;i<SIZE;i++)
    {
        printf("%d ",*(usernumbers+i));
    }
    printf("\n");
}//end funcion

//Option 3
void sortarray(int usernumbers[])
{
    int i;
    int j;
    int temp;
    //This is the bubble sort algorithm, I used this algorithm as it was easy to implement and understand
    for(i = SIZE - 1; i >= 1; i--)
    {
        for(j=0;j< i;j++)
        {
            if(*(usernumbers+j) > *(usernumbers+(j+1)))
            {
                temp = *(usernumbers+(j+1));
                *(usernumbers+(j+1)) = *(usernumbers+j);
                *(usernumbers+j) = temp;
            }// end if
        }// end for
    }//end for
    
    printf("\nNumbers have been sorted\n");
}//end function

//Option 4
void comparearray(int usernumbers[])
{
    int winningnumbers[SIZE] = {1,3,5,7,9,11};
    int bonusnumber = 42;
    int bonus = 0;
    int i;
    int j;
    int counter = 0;
    
    //Used to go through all numbers entered
    for(i=0; i<SIZE; i++)
    {
        //For loop for going through the winning numbers
        for(j=0;j<SIZE;j++)
        {
            //If statement compares entered numbers to the winning numbers
            if(*(usernumbers+i) == *(winningnumbers + j))
            {
                //increments for each correct number entered
                counter++;
            }//end if
        }//end for
        
        //If statement used to check entered numbers to the bonus number
        if(*(usernumbers+i) == bonusnumber)
        {
            bonus++;
        }//end if
    }//end for
    
    //All if statements here are used to check what prize the user won,based on how many they matched.
    if(counter == 6)
    {
        printf("\nYou matched 6! You won the Jackpot!\n");
    }//end if
    
    if(counter == 5 && bonus == 1)
    {
        printf("\nYou matched 5 and the bonus! You won a New Car!\n");
    }//end if
    
    if(counter == 5 && bonus == 0)
    {
        printf("\nYou matched 5! You won a Holiday!\n");
    }//end if
    
    if(counter == 4  && bonus == 1)
    {
        printf("\nYou matched 4 and the bonus! You won a Weekend Away!\n");
    }//end if
    
    if(counter == 4 && bonus == 0)
    {
        printf("\nYou matched 4! You won a Night Out!\n");
    }//end if
    
    if(counter == 3 && bonus == 1)
    {
        printf("\nYou matched 3 and the bonus! You won a Cinema Ticket!\n");
    }//end if
    if(counter <= 3 && bonus == 0)
    {
        printf("\nYou didn't win anything, better luck next time!\n");
    }//end if

}//end function
            
    

//Option 5
void frequency(int allnumbers[])
{
    int i;
    int j = 1;
    
    printf("\n");

    //Used to print array that calculated the frequency of each number entered
    for(i = 1; i < ALLNUMS;i++)
    {
        //If statement used to not print any numbers that havent been used by user yet.
        if(*(allnumbers+i) != 0)
        {
           printf("%d was used %d times\n",j,*(allnumbers+i));
        }//end if
        
        j++;
    }//end for
    printf("\n");
}//end function

//Option 6
int leave(int exit)
{
    int leaving;
    printf("\nAre you sure?");
    printf("\nPress 1 to exit");
    printf("\nPress 0 to keep playing\n");
    scanf("%d",&leaving);
    flushall();
    
    //if else statement used to confirm that the user wants to exit
    if(leaving == 1)
    {
        exit = 1;
        printf("\nThank you for playing! Come again!");
    }
    else
    {
        clrscr();
    }//end if else
    //returns a value to allow the program to exit the do while loop.
    return exit;
}//end function
    
    
    
    
    
    
    
    
    
    
    
    
    
    

