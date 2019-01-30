# 2S03 Assignment 4

This is the code that me and my partner ([Meghan](https://github.com/meghanmazer) and [David](https://github.com/datho7561)) used for our final project in the McMaster C programming course, 2S03.

We were provided the files `a4.h`, `main.c`, `crossover.c`, and the makefile, and were tasked with writing the remaining functions listed in `a4.h`.

The program takes an image, and uses a genetic algorithm to try to replicate it. It generates a population of random images of the same size as the original. It then computes the given number of generations, using the command line parameters for mutation rate, population size, and number of generations. It outputs the most fit image of the last generation. 

The fitness value is based off of the distance of each pixel from the original image.

Mutuation is done by changing random pixels to random values at the given rate.

The crossover was coded by our professor. It takes a percentage of pixels of one image and a percentage of pixels for the other in order to create a child image.

I have included all the provided code as well as the PPM images that were given to us.

### RUNNING

In order to run the code, clone or download the source, and in a terminal, `cd` into the folder, then run `make escher` or `make mcmaster`. This will only work if you have `make` and `gcc` installed. The program will take around 15 minutes to run, and will generate the output file at the end.

Please note that you can also run `make fireball`, but please be advised that it will take several hours to complete, because it is a larger image with more pixels to process.

### VIDEO

As part of an extension for the project, we made a video showing the progress of the algorithm through the generations.

I used the included photo of the McMaster engineering fireball for the video.

As noted above, I included the command line arguments I used to generate the final image in the `makefile`. Modifications to the existing code were made to generate the frames. I left this code commented in the file `mutate.c`.

[Here is a link to the program computing an image.](https://youtu.be/tv-_K_bvpSw)
