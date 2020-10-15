#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "mat.h"

int main(int argc, char const *argv[])
{
    double *a, *b, *c, time_spend;
    clock_t begin, end;
    for (size_t i = 100; i < 1000; i += 100)
    {
        //nonoptimized
        begin = clock();
        a = malloc(i * i * 8);
        b = malloc(i * i * 8);
        a = gen_matrix(i, i);
        b = gen_matrix(i, i);
        c = malloc(i * i * 8);
        mmult(c, a, i, i, b, i, i);
        end = clock();
        time_spend = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("Time use:%f\n", time_spend);
        //simd
        begin = clock();
        a = malloc(i * i * 8);
        b = malloc(i * i * 8);
        a = gen_matrix(i, i);
        b = gen_matrix(i, i);
        c = malloc(i * i * 8);
        mmult_mmult_vectorized(c, a, i, i, b, i, i);
        end = clock();
        time_spend = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("Time use for simd:%f\n", time_spend);
    }
}