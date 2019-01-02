#include "a4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Read a .ppm image into a PPM_IMAGE
PPM_IMAGE *read_ppm(const char *file_name) {

    // String to store the computed magic number
    char magicNum[3];

    int results;

    // Open the file
    FILE * readFile = fopen(file_name, "r");

    // Read the magic number and make sure it is correct
    results = fscanf(readFile, "%s\n", magicNum);

    if (results == EOF) {

        fprintf(stderr, "The image file is empty");

        return NULL;

    } else if (!strcmp(magicNum, "P3")) {

        // If the magic number is correct
        
        // Make an image object and allocate for it
        PPM_IMAGE * readImage = malloc(sizeof(PPM_IMAGE));

        // Read the width, height, and max colour value into the image
        results = fscanf(readFile,
                         "%d %d %d",
                         &(readImage->width),
                         &(readImage->height),
                         &(readImage->max_color));

        // Allocate an array of pixels for the image
        readImage->data = (PIXEL *) malloc(readImage->width * readImage->height * sizeof(PIXEL));

        // For each pixel
        int i;
        unsigned int r, g, b;
        for (i = 0; i < readImage->width * readImage->height; i++) {

            // Read the colour values as unsigned integers
            results = fscanf(readFile, "%u %u %u", &r, &g, &b);

            // Convert the read numbers into unsigned characters and put them into the pixel
            readImage->data[i].r = (unsigned char)r;
            readImage->data[i].g = (unsigned char)g;
            readImage->data[i].b = (unsigned char)b;

        }

        // Close the file from reading
        fclose(readFile);

        // Return the created image
        return readImage;

    } else {

        // The magic number does not match

        // Spit out an error message
        fprintf(stderr, "The file had an incorrect magic number: '%s'\n", magicNum);

        // Close the file
        fclose(readFile);

        return NULL;

    }

}



// Write a PPM_IMAGE to file as a .ppm
void write_ppm(const char *file_name, const PPM_IMAGE *image) {

    FILE * writtenFile = fopen(file_name, "w");

    // Write the magic number
    fprintf(writtenFile, "P3\n");

    // Write width, height, and max colour
    fprintf(writtenFile, "%d %d\n%d\n", image->width, image->height, image->max_color);

    int row, col;

    // Used to point to the pixels when going through the list
    PIXEL * pixelIterator = image->data;

    for (row = 0; row < image->height; row++) {

        for (col = 0; col < image->width; col++) {

            // Print the data associated with the pixel into the file
            fprintf(writtenFile, "%u %u %u\t",
                    (unsigned int)(pixelIterator->r),
                    (unsigned int)(pixelIterator->g),
                    (unsigned int)(pixelIterator->b));
            
            pixelIterator++;

        }

        fprintf(writtenFile, "\n");

    }

    // Close the file
    fclose(writtenFile);

}