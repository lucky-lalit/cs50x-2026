#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // printf("%i %i %i\n",image[i][j].rgbtRed,image[i][j].rgbtGreen,image[i][j].rgbtBlue);
            average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);
            if (sepiaRed <= 255 && sepiaGreen <= 255 && sepiaBlue <= 255)
            {
                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                if (sepiaRed > 255)
                    // {
                    sepiaRed = 255;
                // image[i][j].rgbtGreen = sepiaGreen;
                // image[i][j].rgbtBlue = sepiaBlue;
                // }
                if (sepiaGreen > 255)
                    // {
                    // image[i][j].rgbtRed = sepiaRed;
                    sepiaGreen = 255;
                // image[i][j].rgbtBlue = sepiaBlue;
                // }
                if (sepiaBlue > 255)
                    // {
                    // image[i][j].rgbtRed = sepiaRed;
                    // image[i][j].rgbtGreen = sepiaGreen;
                    sepiaBlue = 255;
                // }
                // else if (sepiaRed > 255 && sepiaGreen > 255)
                // {
                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue;
                // }
                // else if (sepiaGreen > 255 && sepiaBlue > 255)
                // {
                // image[i][j].rgbtRed = sepiaRed;
                // image[i][j].rgbtGreen = 255;
                // image[i][j].rgbtBlue = 255;
                // }
                // else if (sepiaRed > 255 && sepiaBlue > 255)
                // {
                // image[i][j].rgbtRed = 255;
                // image[i][j].rgbtGreen = sepiaGreen;
                // image[i][j].rgbtBlue = 255;
                // }
                // else
                // {
                // image[i][j].rgbtRed = 255;
                // image[i][j].rgbtGreen = 255;
                // image[i][j].rgbtBlue = 255;
                // }
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // for (int k = j; k <= j; k++)
            // {

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
            // }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)

    {
        for (int j = 0; j < width; j++)
        {
            int count = 1;
            int redcolor = copy[i][j].rgbtRed;
            int greencolor = copy[i][j].rgbtGreen;
            int bluecolor = copy[i][j].rgbtBlue;
            if (i - 1 >= 0)
            {
                redcolor += copy[i - 1][j].rgbtRed;
                greencolor += copy[i - 1][j].rgbtGreen;
                bluecolor += copy[i - 1][j].rgbtBlue;
                count++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                redcolor += copy[i - 1][j - 1].rgbtRed;
                greencolor += copy[i - 1][j - 1].rgbtGreen;
                bluecolor += copy[i - 1][j - 1].rgbtBlue;
                count++;
            }
            if (j - 1 >= 0)
            {
                redcolor += copy[i][j - 1].rgbtRed;
                greencolor += copy[i][j - 1].rgbtGreen;
                bluecolor += copy[i][j - 1].rgbtBlue;
                count++;
            }
            if (i + 1 < height)
            {
                redcolor += copy[i + 1][j].rgbtRed;
                greencolor += copy[i + 1][j].rgbtGreen;
                bluecolor += copy[i + 1][j].rgbtBlue;
                count++;
            }
            if (j + 1 < width)
            {
                redcolor += copy[i][j + 1].rgbtRed;
                greencolor += copy[i][j + 1].rgbtGreen;
                bluecolor += copy[i][j + 1].rgbtBlue;
                count++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                redcolor += copy[i + 1][j + 1].rgbtRed;
                greencolor += copy[i + 1][j + 1].rgbtGreen;
                bluecolor += copy[i + 1][j + 1].rgbtBlue;
                count++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                redcolor += copy[i + 1][j - 1].rgbtRed;
                greencolor += copy[i + 1][j - 1].rgbtGreen;
                bluecolor += copy[i + 1][j - 1].rgbtBlue;
                count++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                redcolor += copy[i - 1][j + 1].rgbtRed;
                greencolor += copy[i - 1][j + 1].rgbtGreen;
                bluecolor += copy[i - 1][j + 1].rgbtBlue;
                count++;
            }
            // printf("debug0 %i %i %i\n",redcolor,greencolor,bluecolor);
            // printf("debug1 %i\n", count);
            // printf("debug2 %i\n",redcolor / count);
            image[i][j].rgbtRed = round(redcolor * 1.0 / count * 1.0);
            image[i][j].rgbtGreen = round(greencolor * 1.0 / count * 1.0);
            image[i][j].rgbtBlue = round(bluecolor * 1.0 / count * 1.0);
        }
    }
    return;
}
