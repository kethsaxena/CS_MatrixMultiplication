#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "sys/time.h"

#define TRIALS 1
//#define BLOCK_MIN 256
#define BLOCK_MAX 1000
#define MATRIX_SIZE 1000

short A[MATRIX_SIZE][MATRIX_SIZE],
      B[MATRIX_SIZE][MATRIX_SIZE],
      C[MATRIX_SIZE][MATRIX_SIZE];


int main() 
{ 

    
	printf("GRID:%dx%d\n",MATRIX_SIZE,MATRIX_SIZE);		        
		
    int i, j, k; 
    
    clock_t start = clock();
			
    // Initalize array A and B with '1's
    for (int i = 0; i < MATRIX_SIZE; ++i)
        for (int k = 0; k < MATRIX_SIZE; ++k)
            A[i][k] = B[i][k] = 1;

    //simple matrix multiplication
    for (i = 0; i < MATRIX_SIZE; i++) 
    { 
        for (j = 0; j < MATRIX_SIZE; j++) 
        { 
            C[i][j] = 0; 
            for (k = 0; k < MATRIX_SIZE; k++) 
                C[i][j] += A[i][k]*B[k][j]; 
        } 
    }

    
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    
    printf("%f Elapsed seconds ", time_elapsed_in_seconds);
    fflush(stdout);
    puts("");

    return 0; 
} 