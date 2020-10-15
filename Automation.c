#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "mat.h"



int main(int argc, char const *argv[]){
    
    for (size_t i = 0; i < 1000; i+100)
    { 
        clock_t begin =clock();
        int *a = malloc(i*8);
        int *b = malloc(i*8);
        a = gen_matrix(i,i);
        b = gen_matrix(i,i);
        int *c = malloc(i*8);
        mmult(c,a,i,i,b,i,i);
        clock_t end =clock();
        double time_spend =((double) (end - begin)) / CLOCKS_PER_SEC; 
        printf("Time use:%f",time_spend);
    }
    
}