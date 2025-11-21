/* main.c */
#include <stdio.h>
#include <stdlib.h>

#include "png.h"

int main(int argc, char *argv[]) {
        /* Verify we specify exactly one file and a grid size */
        if(argc != 4) {
                printf("Usage: %s FILE WIDTH HEIGHT \n", argv[0]);
                printf("Convert FILE from a PNG image to ASCII with grid WIDTH x HEIGHT\n");
                exit(1);
        }

        /* Open the input file to be read */
        FILE *img;
        if((img = fopen(argv[1], "r")) == NULL) {
                printf("%s: Cannot open file %s\n", argv[0], argv[1]);
                exit(1);
        }

        /* Check PNG header */
        if(validate(img)) {
                printf("%s: %s does not have a valid header. Is this a PNG?\n", argv[0], argv[1]);
                fclose(img);
                exit(1);
        }

        /* Get the size of the PNG */
        int *size = dim(img);
        int imgw = size[0];
        int imgh = size[1];

        /* Free up memory from the array */
        free(size);

        /* Once the program is done, close the file and quit gracefully */
        fclose(img);
        return 0;
}
