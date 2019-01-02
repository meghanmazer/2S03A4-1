#include <stdlib.h>
#include <stdio.h>
#include "a4.h"

void mutate(Individual *individual, double rate){
    // Individual (aka image) has a pixel array
    int n = (individual->image).width * (individual->image).height; // image size

    int selectPixels = (int)(n * (rate/100)); // Selects random pixels

    int i;

    for (i = 0; i < selectPixels; i++){ // For every random pixel
        
        int numberOfPixelBeingMutated = rand()%n;

        PIXEL *toChange = &(((individual->image).data[numberOfPixelBeingMutated]));

        toChange->r = (unsigned char)(rand() % (individual->image.max_color + 1)); // Randomize red value
        toChange->g = (unsigned char)(rand() % (individual->image.max_color + 1)); // Randomize green value
        toChange->b = (unsigned char)(rand() % (individual->image.max_color + 1)); // Randomize blue value
    }

}

void mutate_population(Individual *individual, int population_size, double rate){

    int begin = population_size / 4; // Start at index population_size/4
    int i;
    for (i = begin; i < population_size; i++){ // From index beginning to end of population
        mutate((individual + i), rate); // Mutate individual, move pointer
    }

}
