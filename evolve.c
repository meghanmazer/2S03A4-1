#include <stdlib.h>
#include <stdio.h>
#include "a4.h"

// Comparison function taken from TutorialsPoint.com, used in qsort
static int cmpfunc(const void *a, const void *b) {
  return ((*((Individual *)a)).fitness - (*((Individual *)b)).fitness);
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){

    // GENERATE POPULATION OF POPULATION SIZE
    Individual *population = generate_population(population_size, image->width, image->height, image->max_color);

    int num_pixels = image->width * image->height;
    int i;

    // Used to generate string for video output
    //char outputFile[50];

    // Get fitness and sort
    comp_fitness_population(image->data, population, population_size);
    qsort(population, population_size, sizeof(Individual), cmpfunc);

    // From generation 1 to number of generations desired
    for (i = 1; i <= num_generations; i++) {

        // Crossover the population to make new ones
        crossover(population, population_size);

        // Mutate the population to try to improve it
        mutate_population(population, population_size, rate);

        // Get fitness and sort
        comp_fitness_population(image->data, population, population_size);
        qsort(population, population_size, sizeof(Individual), cmpfunc);

        // DEBUGGING AND VIDEO CODE
        //if ((i % 10) == 0) {
        //    printf("Generation #%d, Fitness: %.8e\n", i, population[0].fitness);
        //    sprintf(outputFile, "output/frame%09d.ppm", i);
        //    write_ppm(outputFile, &(population[0].image));
        //}

    }

    // Make a new PPM image to store the result
    PPM_IMAGE *best = malloc(sizeof(PPM_IMAGE));
    best->width = image->width;
    best->height = image->height;
    best->max_color = image->max_color;
    best->data = generate_random_image(image->width, image->height, image->max_color);

    // transfer the pixels to the new image
    for (i = 0; i < num_pixels; i++) {

        (best->data)[i].r = population[0].image.data[i].r;
        (best->data)[i].g = population[0].image.data[i].g;
        (best->data)[i].b = population[0].image.data[i].b;

    }

    // Free all the other images
    for (i = 0; i < population_size; i++) {

        free(population[i].image.data);

    }

    // Free the population data
    free(population);

    // Return the copy of the most fit image
    return best;

}


void free_image(PPM_IMAGE *p) {

    // If the image was read correctly, free it
    if (p) {
        if (p->data) {
            free(p->data);
        }
        free(p);
    }

}
