/*
 Name: Tolaz Hewa
 Date: September 22, 2015
 Course: CPS305
 Professor: Denise Woit
 Project: Assignment 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*
 a struct that defines a complex number
 */
typedef struct {
    int real_part;
    int imag_part;
} complex ;

/*
 All the prototypes for the methods and functions in the class
 */
int process(complex **M, int i, int j, char* buffer);
void displayStats(int f, int m, int h, int c);
void simpleHint(complex **M, int N);
void moderateHint(complex **M, int N);
void strongHint(complex **M, int N);
void loop(complex **M, unsigned int N);


/*
 main method that starts the program
 */
int main(int argc, char *argv[])
{
    //Variables
    unsigned int i, N;
    complex **M;
    
    //Assigning size of array

    if(argc > 1)
    {
        N = (int)strtol(argv[1], NULL, 10);
    }
    
    else
    {
        N = 5;
    }
    
    if(N == 0)
    {
        N = 5;
    }
    
    //creating the 2 dimensional array using memory allocation
    M = (complex **)malloc(sizeof(complex *)*N);
    for(i=0; i < N; i++)
    {
        M[i] = (complex *)malloc(sizeof(complex)*N);
    }
    
    //actual loop
    loop(M,N);
    
    //end of program
    return 0;
}

/*
 Method that presents a loop that runs the game
 */
void loop(complex **M, unsigned int N)
{
    //initiation of time based randomness
    srand ((unsigned)time(NULL));
    
    //instantiation and Declerations
    char* buffer = (char*)malloc(sizeof(char) * 128);
    int loop1 = 1, loop2 = 1, i, j, multiTry = 0, hintAns = 0, firstTime = 0, hintUsed = 0, tryCount = 0, count = 0;
    
    //menu options
    printf("\nH: Simple Hint\nHH: Moderate Hint\nHHH: Strong Hint\nQ: Quit\n\n");
    
    //initial loop to assign new random i and j values and move on to loop 2.
    while(loop1 == 1)
    {
        //assigning random i and j values
        i = rand() % N;
        j = rand() % N;
        
        //second loop that gets user input, checks for their requests and applies them.
        while(loop2 == 1)
        {
            //getting user input
            printf("M[0][0]=%p. M[i][j]=%p  What's i and j? (or Q or H or HH or HHH): ",&M[0][0],&M[i][j]);
            fgets(buffer, 128, stdin);
            
            //statements to check user input
            if(strcmp(buffer, "H\n") == 0) //simple hint
            {
                simpleHint(M, N);
                hintUsed = 1;
            }
            else if(strcmp(buffer, "HH\n") == 0)//moderate hint
            {
                moderateHint(M, N);
                hintUsed = 1;
            }
            else if(strcmp(buffer, "HHH\n") == 0)//strong hint
            {
                strongHint(M, N);
                hintUsed = 1;
            }
            else if(strcmp(buffer, "Q\n") == 0 || strcmp(buffer, "q\n") == 0) //exiting and statistics
            {
                loop2 = 0, loop1 = 0;
                displayStats(firstTime, multiTry, hintAns, count);
            }
            else //checking for user input against i and j values
            {
                loop2 = process(M, i, j, buffer);
                if(loop2 == 0) //gathering info for statistics
                {
                    if(hintUsed == 1)
                    {
                        hintAns++;
                        count++;
                    }
                    else if(hintUsed == 0 && tryCount < 2)
                    {
                        firstTime++;
                        count++;
                    }
                    else if(hintUsed == 0 && tryCount >= 2)
                    {
                        multiTry++;
                        count++;
                    }
                    
                }
                else if(loop2 == 2)
                {
                    loop2 = 0;
                }
                
                else
                {
                    tryCount++;
                }
                
            }
        }
        loop2 = 1, hintUsed = 0, tryCount = 0; //reseting the variables
    }
}

/*
 this method ensures proper input and checks if the guess is correct
 */
int process(complex **M, int i, int j, char* buffer)
{
    //declerations
    int bufferLength = (int)strlen(buffer) - 2;
    int x, isValid = 1, spaceCount = 0, v1, v2;
    
    //checking if all the characters of the input are digits and count spaces
    for(x = 0; x < bufferLength+1; x++)
    {
        if(buffer[x] == ' ' && spaceCount < 1 && x != 0)
        {
            spaceCount++;
        }
        else if(!isdigit(buffer[x]))
        {
            printf("Invalid entry...\n");
            isValid = 0;
            return 2;
        }
    }
    
    //checks if there is at least one space between the numbers, if not returns with a message
    if(spaceCount < 1 && isValid)
    {
        printf("Please enter two values!\n");
        return 2;
    }
    
    //if all the checks go through, this does the checking if the user is correct
    else if(isValid == 1)
    {
        v1 = (int)strtol(buffer, &buffer, 10); //getting user's i value
        v2 = (int)strtol(buffer, NULL, 10); //getting user's j value
        if(i == v1 && j == v2) //checks if user is right
        {
            printf("RIGHT!\n");
            return 0;
        }
        else
        {
            printf("WRONG!\n");
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
/*
 Displaying the users statistics through out the execution of the program
 */
void displayStats(int f, int m, int h, int c)
{
    printf("---------------------------------------------------\n");
    printf("%d\t\t Total number\n", c);
    if(c > 0) //checks if there is 1 or more input
    {
        printf("%d%%\t\t Correct first time (no hints)\n", ((f*100)/c));
        printf("%d%%\t\t Correct after 2 or more guesses (no hints)\n", ((m*100)/c));
        printf("%d%%\t\t Correct after hint(s)\n", ((h*100)/c));
    }
    else //in case there is no input
    {
        printf("0%%\t\t Correct first time (no hints)\n");
        printf("0%%\t\t Correct after 2 or more guesses (no hints)\n");
        printf("0%%\t\t Correct after hint(s)\n");
    }
    printf("---------------------------------------------------\n");
}

/*
 function to display the simple hint
 */
void simpleHint(complex **M, int N)
{
    printf("\n--Simple Hint--\n\n\n");
    int i;
    for(i = 0; i < N; i++)
    {
        printf("M[%d][0] %p \n", i, &M[i][0]);
    }
    printf("\n\n");
}

/*
 function to display the moderate hint
 */
void moderateHint(complex **M, int N)
{
    int i;
    printf("\n--Moderate Hint--\n\n\t");
    for(i = 0; i < N; i++)
    {
        printf("M[0][%d]\t\t", i);
    }
    printf("\nM[0][0] ");
    
    for(i = 0; i < N; i++)
    {
        printf("%p\t", &M[0][i]);
    }
    printf("\n");
    for(i = 1; i < N; i++)
    {
        printf("M[%d][0] %p \n", i, &M[i][0]);
    }
    printf("\n\n");
}

/*
 function to display the strong hint
 */
void strongHint(complex **M, int N)
{
    int i,j;
    printf("\n--Strong Hint--\n\n\t");
    for(i = 0; i < N; i++)
    {
        printf("M[0][%d]\t\t", i);
    }
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("M[%d][0] ", i);
        for(j = 0; j < N; j++)
        {
            printf("%p\t", &M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

