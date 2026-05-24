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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            int gxredcolor = copy[i][j].rgbtRed * 0;
            int gxgreencolor = copy[i][j].rgbtGreen * 0;
            int gxbluecolor = copy[i][j].rgbtBlue * 0;
            int gyredcolor = copy[i][j].rgbtRed * 0;
            int gygreencolor = copy[i][j].rgbtGreen * 0;
            int gybluecolor = copy[i][j].rgbtBlue * 0;
            if (i - 1 >= 0)
            {
                gxredcolor += copy[i - 1][j].rgbtRed * 0;
                gxgreencolor += copy[i - 1][j].rgbtGreen * 0;
                gxbluecolor += copy[i - 1][j].rgbtBlue * 0;
                gyredcolor += copy[i - 1][j].rgbtRed * -2;
                gygreencolor += copy[i - 1][j].rgbtGreen * -2;
                gybluecolor += copy[i - 1][j].rgbtBlue * -2;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                gxredcolor += copy[i - 1][j - 1].rgbtRed * -1;
                gxgreencolor += copy[i - 1][j - 1].rgbtGreen * -1;
                gxbluecolor += copy[i - 1][j - 1].rgbtBlue * -1;
                gyredcolor += copy[i - 1][j - 1].rgbtRed * -1;
                gygreencolor += copy[i - 1][j - 1].rgbtGreen * -1;
                gybluecolor += copy[i - 1][j - 1].rgbtBlue * -1;
            }
            if (j - 1 >= 0)
            {
                gxredcolor += copy[i][j - 1].rgbtRed * -2;
                gxgreencolor += copy[i][j - 1].rgbtGreen * -2;
                gxbluecolor += copy[i][j - 1].rgbtBlue * -2;
                gyredcolor += copy[i][j - 1].rgbtRed * 0;
                gygreencolor += copy[i][j - 1].rgbtGreen * 0;
                gybluecolor += copy[i][j - 1].rgbtBlue * 0;
            }
            if (i + 1 < height)
            {
                gxredcolor += copy[i + 1][j].rgbtRed * 0;
                gxgreencolor += copy[i + 1][j].rgbtGreen * 0;
                gxbluecolor += copy[i + 1][j].rgbtBlue * 0;
                gyredcolor += copy[i + 1][j].rgbtRed * 2;
                gygreencolor += copy[i + 1][j].rgbtGreen * 2;
                gybluecolor += copy[i + 1][j].rgbtBlue * 2;
            }
            if (j + 1 < width)
            {
                gxredcolor += copy[i][j + 1].rgbtRed * 2;
                gxgreencolor += copy[i][j + 1].rgbtGreen * 2;
                gxbluecolor += copy[i][j + 1].rgbtBlue * 2;
                gyredcolor += copy[i][j + 1].rgbtRed * 0;
                gygreencolor += copy[i][j + 1].rgbtGreen * 0;
                gybluecolor += copy[i][j + 1].rgbtBlue * 0;
            }
            if (i + 1 < height && j + 1 < width)
            {
                gxredcolor += copy[i + 1][j + 1].rgbtRed * 1;
                gxgreencolor += copy[i + 1][j + 1].rgbtGreen * 1;
                gxbluecolor += copy[i + 1][j + 1].rgbtBlue * 1;
                gyredcolor += copy[i + 1][j + 1].rgbtRed * 1;
                gygreencolor += copy[i + 1][j + 1].rgbtGreen * 1;
                gybluecolor += copy[i + 1][j + 1].rgbtBlue * 1;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                gxredcolor += copy[i + 1][j - 1].rgbtRed * -1;
                gxgreencolor += copy[i + 1][j - 1].rgbtGreen * -1;
                gxbluecolor += copy[i + 1][j - 1].rgbtBlue * -1;
                gyredcolor += copy[i + 1][j - 1].rgbtRed * 1;
                gygreencolor += copy[i + 1][j - 1].rgbtGreen * 1;
                gybluecolor += copy[i + 1][j - 1].rgbtBlue * 1;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                gxredcolor += copy[i - 1][j + 1].rgbtRed * 1;
                gxgreencolor += copy[i - 1][j + 1].rgbtGreen * 1;
                gxbluecolor += copy[i - 1][j + 1].rgbtBlue * 1;
                gyredcolor += copy[i - 1][j + 1].rgbtRed * -1;
                gygreencolor += copy[i - 1][j + 1].rgbtGreen * -1;
                gybluecolor += copy[i - 1][j + 1].rgbtBlue * -1;
            }
            // printf("debug0 %i %i %i\n",redcolor,greencolor,bluecolor);
            // printf("debug1 %i\n", count);
            // printf("debug2 %i\n",redcolor / count);
            int redsum = round(sqrt((pow(gxredcolor, 2) + pow(gyredcolor, 2))));
            int greensum = round(sqrt((pow(gxgreencolor, 2) + pow(gygreencolor, 2))));
            int bluesum = round(sqrt((pow(gxbluecolor, 2) + pow(gybluecolor, 2))));
            if (redsum > 255)
                redsum = 255;
            if (greensum > 255)
                greensum = 255;
            if (bluesum > 255)
                bluesum = 255;
            image[i][j].rgbtRed = redsum;
            image[i][j].rgbtGreen = greensum;
            image[i][j].rgbtBlue = bluesum;
        }
    }
    return;
}
