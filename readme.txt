High-Level Summary:
------------------

User is given a pointer (address) of some random item in the 2-D array.  
User must guess the corresponding INDEX of the array (i and j values). 
This guessing game repeats for various addresses in the array, until the
user Quits.


Detailed Instructions:
---------------------

Implement a program named guesser.c 
It MUST use the following algorithm; the only exception being that you may 
organize your looping differently, as long as the functionality is equivalent:
  
ALGORITHM:
   -Dynamically allocate a square, 2-D array of complex numbers, as outlined 
    below in "Properties of the 2-D Array".
   -Fill the array with any complex numbers you wish (optional). 
   -loop1: loop until user enters Q to quit 
      -randomly generate two integers, i and j, where each are in [0,N-1]
      -loop2: loop as appropriate
         -display the pointer which is the ADDRESS of array entry [0][0] 
          (so user knows where array starts in memory)
         -display the pointer which is the ADDRESS of array entry [i][j] 
         -ask user for input, which may be any of:
	   i j  : a guess for the corresponding i and j values
           Q    : to quit program
	   H    : for a simple hint
	   HH   : for a moderate hint
	   HHH  : for a strong hint
         -read user response, and perform appropriate action:
             i j : if correct, congratulate and continue loop1
                   if incorrect, display message and continue loop2
             Q   : display statistics and then terminate program
	     H   : display simple   hint then continue loop2
	     HH  : display moderate hint then continue loop2
	     HHH : display strong   hint then continue loop2

Properties of the 2-D Array:
---------------------------
  Your array (and program) MUST conform to the following:
    -Array is square, of size NxN, where N is given as a command-line 
     argument (N defaults to 5 if argument incorrect or missing)
    -Allocate array using DYNAMIC MEMORY ALLOCATION (malloc) only
    -Array MUST be  indexable, i.e., you must be able to refer to items
     using indexes, as in: M[i][j] 
    -Array entries MUST be COMPLEX NUMBERS, as defined in mathematics.
     Note that complex numbers have two parts: real and imaginary. 
     They are often written mathematically as, for example, 5+9i 
    -Complex numbers in your program MUST be defined using the following:
           typedef struct {
             int real_part;
             int imag_part;
           } complex ;

Hints:
------
   H   : display addresses of column 0. For N=5, the hint would look like 
         the following (where Pij is the appropriate address, printed with %p)
          M[0][0] P00
          M[1][0] P10
          M[2][0] P20
          M[3][0] P30
          M[4][0] P40

   HH  : display ADDRESSES of the first row AND first column. For N=5, the
         hint would look like the following (where Pij is the appropriate 
         address, printed with %p)
                  M[0][0]   M[0][1]   M[0][2]   M[0][3]   M[0][4]   
          M[0][0] P00       P01       P02       P03       P04
          M[1][0] P10
          M[2][0] P20
          M[3][0] P30
          M[4][0] P40
   HHH : display ADDRESSES of the whole array. For N=5, the hint would look 
         like the following (where Pij is the appropriate address, printed 
         with %p)
                  M[0][0]   M[0][1]   M[0][2]   M[0][3]   M[0][4]   
          M[0][0] P00       P01       P02       P03       P04
          M[1][0] P10       P11       P12       P13       P14
          M[2][0] P20       P21       P22       P23       P24
          M[3][0] P30       P31       P32       P33       P34
          M[4][0] P40       P41       P42       P43       P44

Statistics:
-----------
  Display at least the following stats: 
    -Total number of unique random addresses generated (similar to the number 
     of iterations of loop1).
    -Percent user guessed correctly the first time without using any hints. 
    -Percent user guessed correctly after 2 or more guesses without using any hints. 
    -Percent user guessed correctly after needing one or more hints. 
  You may display any additional stats you wish.
  An example run is provided below.

Random Numbers:
--------------
  Seed the random number generator with a value such as "time" or "process ID" 
  so that it will produce a different sequence of numbers each program run.
  e.g.:  srand((unsigned)time(NULL));
  Note that a statement such as 
  ( rand() % 5 ) ; 
  will produce a random number between 0 and 4. It will not produce a uniform 
  distribution; however, it is acceptable for this assignment.

Robustness and Assumptions:
--------------------------
 -Your program should handle unexpected/incorrect input appropriately.
 -You may assume malloc will always be able to get the requested memory
  (no error-checking necessary). 
 -File A1addendum.txt will be updated periodically with additional assignment
  assumptions and QA. Everything in A1addendum.txt must also be considered 
  part of this assignment.

Grading:
--------
 On a CS moon only, we will compile and run your guesser.c 

 -The assignment mark IS ZERO for:
   -incorrectly named files (includes case!!)
   -A1cert.txt missing or incorrectly filled-in
   -code does not compile 
   -code compiles, but is not a good attempt at solving the problem
    (too simplistic, etc.)

 If not zero, then the mark includes, but is not limited to, the 
 following. Note that if the submission is incomplete, then the
 Style/Documentation/Modularity mark is also reduced accordingly.

 -Style and Documentation (15%)
    -simple, clear, readable code
    -function header comments
    -internal documentation only of complicated parts
    -indentation, formatting, use of whitespace (indent with either tabs
     or spaces, but not both mixed). Your code should look properly 
     formatted when displayed with moon "cat" command.
    -meaningful, consistent function and variable names

-Modularity  (10%)
       Good use of helper functions.  If a task is repeated, use a helper 
       function, NOT (nearly) duplicate code.  If a function is too long, 
       consider dividing it into sub-functions, even if they are called 
       only once. Too long is about 30LOC. Divide even short chunks of
       code into functions to increase readability of your code.

 -Functionality (75%)
    -correctness (when following assignment instructions)
     Your program may produce required results, but will be worth nothing
     unless it does so by following assignment instructions/requirements.
    -correctness is measured ONLY by the grader's own tests. 

Suggestions:
-----------
  -Dynamic Allocation:
   The following code dynamically allocates a 2-D array of size N*N of 
   unsigned integers. You could follow this general pattern to dynamically 
   declare your array of complex numbers.  The casting is there for clarity, 
   but is optional:

    unsigned int **M;
    M = (unsigned int **)malloc(sizeof(unsigned int *)*N);
    for(i=0; i < N; i++) 
      M[i] = (unsigned int *)malloc(sizeof(unsigned int)*N);

  -Filling the Array:
   The algorithm states: 
     "-fill the array with any complex numbers you wish (optional). "
   This is optional because your program uses only the ADDRESSES of the
   array items, not their contents. However, you might find it useful to
   fill the array with some values (complex numbers) to help you debug
   your code. You could also use such values to double-check that the
   user has guessed the correct index.

Example Run:
------------
Here is an example of running checker.c (compiled into a.out). Note 
that "dwoit> " is simply the command-line prompt.
Your messages and prompting can differ, as long as the functionality is equivalent.
These pointers were printed with %p, but you may use %x if you wish.
Note that "Total number" is 4 because the user tried guessing for 4 addresses:
0x1aa4050, 0x1aa4118, 0x1aa40b8, 0x1aa40b0.

dwoit> a.out 5
M[0][0]=0x1aa4040. M[i][j]=0x1aa4050  What's i and j? (or Q or H or HH or HHH): 0 2
RIGHT
M[0][0]=0x1aa4040. M[i][j]=0x1aa4118  What's i and j? (or Q or H or HH or HHH): 4 3
RIGHT
M[0][0]=0x1aa4040. M[i][j]=0x1aa40b8  What's i and j? (or Q or H or HH or HHH): 2 4
WRONG
M[0][0]=0x1aa4040. M[i][j]=0x1aa40b8  What's i and j? (or Q or H or HH or HHH): 2 3
RIGHT
M[0][0]=0x1aa4040. M[i][j]=0x1aa40b0  What's i and j? (or Q or H or HH or HHH): 3 1
WRONG
M[0][0]=0x1aa4040. M[i][j]=0x1aa40b0  What's i and j? (or Q or H or HH or HHH): HH

        M[0][0]   M[0][1]   M[0][2]   M[0][3]   M[0][4]   
M[0][0] 0x1aa4040 0x1aa4048 0x1aa4050 0x1aa4058 0x1aa4060 
M[1][0] 0x1aa4070  
M[2][0] 0x1aa40a0  
M[3][0] 0x1aa40d0  
M[4][0] 0x1aa4100  
M[0][0]=0x1aa4040. M[i][j]=0x1aa40b0  What's i and j? (or Q or H or HH or HHH): 2 2
RIGHT
M[0][0]=0x1aa4040. M[i][j]=0x1aa40e8  What's i and j? (or Q or H or HH or HHH): Q
------------------------------------------------------
4       Total number
50%     Correct first time (no hints)
25%     Correct after 2 or more guesses (no hints)
25%     Correct after hint(s)
------------------------------------------------------ 

