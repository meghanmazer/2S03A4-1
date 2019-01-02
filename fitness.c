#include <stdlib.h>
#include <math.h>
#include "a4.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
    
    double sum = 0;
    int i;
    for (i = 0; i < image_size; i++){

        double d = ((A[i].r - B[i].r)*(A[i].r - B[i].r)) + ((A[i].g - B[i].g)*(A[i].g - B[i].g)) + ((A[i].b - B[i].b)*(A[i].b - B[i].b));
        sum += d;

    }

    return sqrt(sum);
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){

    int image_size = individual->image.width * individual->image.height;
    int i;
    for (i = 0; i < population_size; i++){

        individual[i].fitness = comp_distance(image, individual[i].image.data, image_size);
    
    }
    
}
