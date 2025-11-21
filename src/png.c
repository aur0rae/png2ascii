/* png.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "png.h"

/* Test whether or not a file is a PNG */
int validate(FILE *fname) {
        /* Go to the start of the file */
        rewind(fname);

        /* Collect PNG signature */
        unsigned char sig[8];
        fread(sig, 1, 8, fname);

        /* Check it against a good sig */
        unsigned char sigv[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};

        for(size_t i = 0; i < 8; i++) {
                if(sig[i] != sigv[i]) {
                        /* Does not match, error and exit the program */
                        return 1;
                }
        }

        /* Return "good" */
        return 0;
}

/* Determine starting dimensions of the input image */
int *dim(FILE *fname) {
        /* The first chunk after the header contains basic file info              */
        /* We skip the first 8 bytes of this chunk as we know it must be the IHDR */
        fseek(fname, 16, SEEK_SET);
        char buf[8];
        int *size = (int *)malloc(sizeof(int) * 2);

        /* Convert 4 bytes of binary to decimal (big endian) for width and height */
        fread(buf, 1, 8, fname);
        size[0] = abs((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8)| buf[3]);
        size[1] = abs((buf[4] << 24) | (buf[5] << 16) | (buf[6] << 8)| buf[7]);

        /* Return the size as arr[2] = {W, H} */
        return size;
}
