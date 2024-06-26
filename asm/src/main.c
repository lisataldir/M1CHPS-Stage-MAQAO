#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../include/splat.h"

int main(int argc, char ** argv) {

    if (argc < 3){
        printf("usage: %s [n] [r]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int r = atoi(argv[2]);


    float *result = malloc(sizeof(float)*n);
    float *data = malloc(sizeof(float)*n);

    data[2] = 1;

    for(int k=0; k<r; ++k){
        splat(result, data, n);
        printf("Répétition %d/%d \n", k+1, r);
    }

    return 0;
}