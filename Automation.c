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
    FILE *file;
    char instruction[100];
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
        printf("%4ld,%6ld,%10f,",i/100,i, time_spend);
        //simd
        begin = clock();
        a = malloc(i * i * 8);
        b = malloc(i * i * 8);
        a = gen_matrix(i, i);
        b = gen_matrix(i, i);
        c = malloc(i * i * 8);
        mmult_vectorized(c, a, i, i, b, i, i);
        end = clock();
        time_spend = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("%10f, ", time_spend);
        //OMP
        begin = clock();
        a = malloc(i * i * 8);
        b = malloc(i * i * 8);
        a = gen_matrix(i, i);
        b = gen_matrix(i, i);
        c = malloc(i * i * 8);
        mmult_omp(c, a, i, i, b, i, i);
        end = clock();
        time_spend = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("%10f, ", time_spend);
        //mpi

        sprintf(instruction, "(mpiexec -f ~/hosts -n 4 ./mmult_mpi %d) > mpi_data.txt", i);
        system(instruction);
        file = fopen("mpi_data.txt", "r");
        fscanf(file, "%lf", &time_spend);
        fclose(file);
        printf("%10f\n",time_spend);

    }
}
