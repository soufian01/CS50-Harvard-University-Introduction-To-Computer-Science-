#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512 // Define a block of size 512.

int main(int argc, char *argv[])
{
    // Ensure correct use.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n"); // If the input is not correct tell the user about the usage.
        return 1; // If something went wrong return 1.
    }

    char *raw_file = argv[1];

    FILE *inptr = fopen(raw_file, "r"); // Open the file in reading mode.

    if (inptr == NULL) // Check if the file is empty.
    {
        fprintf(stderr, "Could not open %s\n", raw_file);
        return 2;
    }

    FILE *outptr = NULL; // File pointer.

    int jpeg_count = 0; // Count how many jpegs file found.
    int jpeg_found = 0;
    char title[8]; // Create a size of the filenames for the jpeg files.

    unsigned char buffer[BLOCK];

    while (fread(buffer, BLOCK, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0) // Check the first 4 bytes of the file to check if jpeg is found.
        {
            if (jpeg_found == 1)
            {
                fclose(outptr);

            }
            else
            {
                jpeg_found = 1;

            }
            sprintf(title, "%03d.jpg", jpeg_count++);

            outptr = fopen(title, "w"); // Open the file in writing mode.

        }
        if (jpeg_found == 1)
        {
            fwrite(&buffer, BLOCK, 1, outptr);
        }

    }

    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(inptr);

    return 0;
}
