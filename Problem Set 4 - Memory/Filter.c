#include "helpers.h" // Include the given helpers.h library.
#include <stdio.h>
#include <math.h> // Include the math library to use the round function.

// Function to convert the image to grayscale.
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (&image[i][j] != NULL) // Check if everything right.
            {
                average = round(((float)image[i][j].rgbtRed + (float) image[i][j].rgbtGreen + (float) image[i][j].rgbtBlue) / 3);
                image[i][j].rgbtRed = average;
                image[i][j].rgbtGreen = average;
                image[i][j].rgbtBlue = average;
            }

        }
    }
    printf("%i\n", average);
    return;

}

// Function to convert the image to sepia.
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (&image[i][j] != NULL)
            {
                sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 *
                                 image[i][j].rgbtBlue); // Applicate the formula given to create the correct amount of red.

                sepiaGreen = round(.349 *  image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 *
                                   image[i][j].rgbtBlue); // Applicate the formula given to create the correct amount of green.

                sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 *  image[i][j].rgbtGreen  + .131 *
                                  image[i][j].rgbtBlue); // Applicate the formula given to create the correct amount of blue.

                if (sepiaRed > 255)
                {
                    sepiaRed = 255;
                }

                if (sepiaGreen > 255)
                {
                    sepiaGreen = 255;
                }

                if (sepiaBlue > 255)
                {
                    sepiaBlue = 255;
                }

                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue;
            }

        }
    }
    printf("%f %f %f\n", sepiaRed, sepiaGreen, sepiaBlue);
    return;
    return;
}

// Function to reflect the image horizontally.
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0, w = round((float) width / 2); j < w; j++)
        {
            if (&image[i][j] != NULL)
            {
                RGBTRIPLE temp = image[i][j];

                image[i][j] = image[i][(width - j - 1)];

                image[i][(width - j - 1)] = temp;
            }

        }
    }
    return;
}

// Function to blur the image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE new[height][width]; // Create a new array.


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create counters and int to store each the neighbour colors.
            int counter = 0;
            int tempRed = 0;
            int tempGreen = 0;
            int tempBlue = 0;

            for (int l = -1; l < 2; l++)
            {
                for (int m = -1; m < 2; m++)
                {

                    if (i + l >= 0 && i + l < height && j + m >= 0 && j + m < width)
                    {

                        tempRed += new[i + l][j + m].rgbtRed;
                        tempGreen += new[i + l][j + m].rgbtGreen;
                        tempBlue += new[i + l][j + m].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float)tempRed / (float)counter);
            image[i][j].rgbtGreen = round((float)tempGreen / (float)counter);
            image[i][j].rgbtBlue = round((float)tempBlue / (float)counter);
        }
    }
    return;
}
