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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    //loop through image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_blue = 0;
            int gx_green = 0;
            int gx_red = 0;
            int gy_blue = 0;
            int gy_green = 0;
            int gy_red = 0;

            //loop through pixels surrounding pixels
            for (int a = -1; a < 2; a++)
            {
                if (i + a < 0 || i + a >= height)
                    continue;
                for (int b = -1; b < 2; b++)
                {
                    if (j + b < 0 || j + b >= width)
                        continue;
                    if (a == 0 && b == 0)
                        continue;
                    //calculate gx and gy
                    if (a == -1 && b == -1)
                    {
                        gx_blue = gx_blue + image[i + a][j + b].rgbtBlue * -1;
                        gx_green = gx_green + image[i + a][j + b].rgbtGreen * -1;
                        gx_red = gx_red + image[i + a][j + b].rgbtRed * -1;

                        gy_blue = gy_blue + image[i + a][j + b].rgbtBlue * -1;
                        gy_green = gy_green + image[i + a][j + b].rgbtGreen * -1;
                        gy_red = gy_red + image[i + a][j + b].rgbtRed * -1;
                    }
                    else if (a == -1 && b == 0)
                    {
                        gy_blue = gy_blue + image[i + a][j + b].rgbtBlue * -2;
                        gy_green = gy_green + image[i + a][j + b].rgbtGreen * -2;
                        gy_red = gy_red + image[i + a][j + b].rgbtRed * -2;
                    }
                    else if (a == -1 && b == 1)
                    {
                        gx_blue = gx_blue + image[i + a][j + b].rgbtBlue * 1;
                        gx_green = gx_green + image[i + a][j + b].rgbtGreen * 1;
                        gx_red = gx_red + image[i + a][j + b].rgbtRed * 1;

                        gy_blue = gy_blue + image[i + a][j + b].rgbtBlue * -1;
                        gy_green = gy_green + image[i + a][j + b].rgbtGreen * -1;
                        gy_red = gy_red + image[i + a][j + b].rgbtRed * -1;
                    }
                    else if (a == 0 && b == -1)
                    {
                        gx_blue = gx_blue + image[i + a][j + b].rgbtBlue * -2;
                        gx_green = gx_green + image[i + a][j + b].rgbtGreen * -2;
                        gx_red = gx_red + image[i + a][j + b].rgbtRed * -2;
                    }
                    else if (a == 0 && b == 1)
                    {
                        gx_blue = gx_blue + image[i + a][j + b].rgbtBlue * 2;
                        gx_green = gx_green + image[i + a][j + b].rgbtGreen * 2;
                        gx_red = gx_red + image[i + a][j + b].rgbtRed * 2;
                    }
                    else if (a == 1 && b == -1)
                    {
                        gx_blue = gx_blue + image[i + a][j + b].rgbtBlue * -1;
                        gx_green = gx_green + image[i + a][j + b].rgbtGreen * -1;
                        gx_red = gx_red + image[i + a][j + b].rgbtRed * -1;

                        gy_blue = gy_blue + image[i + a][j + b].rgbtBlue * 1;
                        gy_green = gy_green + image[i + a][j + b].rgbtGreen * 1;
                        gy_red = gy_red + image[i + a][j + b].rgbtRed * 1;
                    }
                    else if (a == 1 && b == 0)
                    {
                        gy_blue = gy_blue + image[i + a][j + b].rgbtBlue * 2;
                        gy_green = gy_green + image[i + a][j + b].rgbtGreen * 2;
                        gy_red = gy_red + image[i + a][j + b].rgbtRed * 2;
                    }
                    else if (a == 1 && b == 1)
                    {
                        gx_blue = gx_blue + image[i + a][j + b].rgbtBlue * 1;
                        gx_green = gx_green + image[i + a][j + b].rgbtGreen * 1;
                        gx_red = gx_red + image[i + a][j + b].rgbtRed * 1;

                        gy_blue = gy_blue + image[i + a][j + b].rgbtBlue * 1;
                        gy_green = gy_green + image[i + a][j + b].rgbtGreen * 1;
                        gy_red = gy_red + image[i + a][j + b].rgbtRed * 1;
                    }
                }
            }
            //calculate and assign image pixels new RGB value
            if (round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2))) > 255)
                temp[i][j].rgbtBlue = 255;
            else
                temp[i][j].rgbtBlue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            if (round(sqrt(pow(gx_green, 2) + pow(gy_green, 2))) > 255)
                temp[i][j].rgbtGreen = 255;
            else
                temp[i][j].rgbtGreen = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));

            if (round(sqrt(pow(gx_red, 2) + pow(gy_red, 2))) > 255)
                temp[i][j].rgbtRed = 255;
            else
                temp[i][j].rgbtRed = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
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