#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <file>");
        return (1);
    }
    FILE *card = fopen(argv[1], "r");
    uint8_t *block;
    int opened_file = 0;
    char filename[8];
    int jpeg = -1;
    FILE *output;

    //reading memory card block by block, each block is 512 bytes
    while (fread(block = malloc(512), 1, 512, card) != 0)
    {
        //making sure malloc returns a pointer
        if (block == NULL)
        {
            return (1);
        }
        //detecting jpeg header
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0) //is new JPEG
        {
            jpeg++;
            //checking if there is already an opened jpeg that needs to be closed before opening another new jpeg
            if (opened_file == 1)
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", jpeg);
            output = fopen(filename, "w");
            opened_file = 1;
            fwrite(block, 1, 512, output);
        }
        //continue to write to current jpeg if no new header detected
        else if (opened_file == 1)
        {
            fwrite(block, 1, 512, output);
        }
        free(block);
    }
    free(block);
}
