#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float newblue;
    float newgreen;
    float newred;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newblue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            if (newblue > 255)
            {
                newblue = 255;
            }
            newgreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            if (newgreen > 255)
            {
                newgreen = 255;
            }
            newred = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            if (newred > 255)
            {
                newred = 255;
            }
            image[i][j].rgbtBlue = round(newblue);
            image[i][j].rgbtGreen = round(newgreen);
            image[i][j].rgbtRed = round(newred);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp.rgbtBlue = image[i][j].rgbtBlue;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtRed = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp.rgbtBlue;
            image[i][width - j - 1].rgbtGreen = temp.rgbtGreen;
            image[i][width - j - 1].rgbtRed = temp.rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int newblue = 0;
            int newgreen = 0;
            int newred = 0;
            int divider = 0;
            for (int a = -1; a < 2; a++)
            {
                if (i + a < 0 || i + a == height)
                    continue;
                for (int b = -1; b < 2; b++)
                {
                    if (j + b < 0 || j + b == width)
                        continue;
                    divider++;
                    newblue = newblue + image[i + a][j + b].rgbtBlue;
                    newgreen = newgreen + image[i + a][j + b].rgbtGreen;
                    newred = newred + image[i + a][j + b].rgbtRed;
                }
            }
            temp[i][j].rgbtBlue = round((float)newblue / divider);
            temp[i][j].rgbtGreen = round((float)newgreen / divider);
            temp[i][j].rgbtRed = round((float)newred / divider);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
