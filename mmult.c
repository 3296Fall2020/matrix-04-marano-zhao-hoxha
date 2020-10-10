/**
 * An unoptimized implementation of matrix multiplication.
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "mat.h"

/**
 * An unoptimized algorithm for matrix multiplication.
 * 
 * @param c : the matrix in which to place the result of the matrix multiplication.
 * @param a : the first matrix.
 * @param aRows : the number of rows in a.
 * @param aCols : the number of columns in a.
 * @param b : the second matrix.
 * @param bRows : the number of rows in b.
 * @param bCols : the number of columns in b.
 * @return 0 if the matrix multiplication is successful.
 */
int mmult(double *c, 
	      double *a, int aRows, int aCols, 
	      double *b, int bRows, int bCols) {
    
    for(int i = 0; i < aRows; ++i) {
        for(int j = 0; j < bCols; ++j) {
            c[i * bCols + j] = 0;
            for(int k = 0; k < aRows; ++k) {
                for (int l = 0; l < bCols; l+=4)
                {
                   c[i * bCols + l] += a[i * aRows + k] * b[k * bCols + l];
                   c[i * bCols + l+1] += a[i * aRows + k] * b[k * bCols + l+1]; 
                   c[i * bCols + l+2] += a[i * aRows + k] * b[k * bCols + l+2]; 
                   c[i * bCols + l+3] += a[i * aRows + k] * b[k * bCols + l+3]; 
                }
            }
        }
    }

  return 0;
}



