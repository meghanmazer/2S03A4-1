#include <stdlib.h>
#include "a4.h"



PIXEL *generate_random_image(int width, int height, int max_color) {

    int num_pixels = width * height;

    PIXEL * rand_img = malloc(num_pixels * sizeof(PIXEL));

    int i;

    for (i = 0; i < num_pixels; i++) {

        rand_img[i].r = rand() % (max_color + 1);
        rand_img[i].g = rand() % (max_color + 1);
        rand_img[i].b = rand() % (max_color + 1);

    }

    return rand_img;

}



Individual *generate_population(int population_size, int width, int height, int max_color) {

    Individual * pop = (Individual*) malloc(population_size * sizeof(Individual));

    int i;

    for (i = 0; i < population_size; i++) {

        pop[i].image.data = generate_random_image(width, height, max_color);
        pop[i].image.width = width;
        pop[i].image.height = height;
        pop[i].image.max_color = max_color;

    }

    return pop;

}