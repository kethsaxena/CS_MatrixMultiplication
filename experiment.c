#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "sys/time.h"

#define TRIALS 1
//#define BLOCK_MIN 256
#define BLOCK_MAX 10000
#define MATRIX_SIZE 10000

short A[MATRIX_SIZE][MATRIX_SIZE],
      B[MATRIX_SIZE][MATRIX_SIZE],
      C[MATRIX_SIZE][MATRIX_SIZE];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char*  argv[])
{
	
		
		printf("GRID:%dx%d\n",MATRIX_SIZE,MATRIX_SIZE);		        
		
		short b_size[] ={50,100,250,300,400,500,600,800,1000};
		int a=sizeof(b_size) / sizeof(b_size[0]);
		
		
		for(int iter=0; iter<a;++iter)
		{
			
			int BLOCK_MIN=b_size[iter];

			
		// Initalize array A and B with '1's
			for (int i = 0; i < MATRIX_SIZE; ++i)
				for (int k = 0; k < MATRIX_SIZE; ++k)
					A[i][k] = B[i][k] = 1;


			// Initalize our matix looping variables once
			int k, j, i, jj, kk;

			// Run TRIALS number of trials for each block size
			for (int trial = 0; trial < TRIALS; ++trial)
			{
				printf("Trial %d: ", (iter+1));
				clock_t start = clock();
		
				// Iterate through the block sizes
				for (int block_size = BLOCK_MIN; block_size <= BLOCK_MAX; block_size *= 2)
				{
					memset(C, 0, sizeof(C[0][0] * MATRIX_SIZE * MATRIX_SIZE));

					// struct timeval time_start;
					// struct timeval time_end;

					// Keep track of when we start doing work
					//gettimeofday(&time_start, NULL);
					
					// Do block matrix multiplication
					for (k = 0; k < MATRIX_SIZE; k += block_size)
						for (j = 0; j < MATRIX_SIZE; j += block_size)
							for (i = 0; i < MATRIX_SIZE; ++i)
								for (jj = j; jj < min(j + block_size, MATRIX_SIZE); ++jj)
									for (kk = k; kk < min(k + block_size, MATRIX_SIZE); ++kk)
										C[i][jj] += A[i][kk] * B[kk][jj];

					// Keep track of when we finish our work
					//gettimeofday(&time_end, NULL);

					
					// Calculate the time it took to do the above task
					// long long execution_time = 1000000LL
					// 	* (time_end.tv_sec  - time_start.tv_sec)
					// 	+ (time_end.tv_usec - time_start.tv_usec);

					
				}

				clock_t end = clock();
				double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
				
				printf("Block size %d |", BLOCK_MIN);
				printf("%f Elapsed seconds ", time_elapsed_in_seconds);
				
				fflush(stdout);

				puts("");

			}
		

		}

	return 0;
}
