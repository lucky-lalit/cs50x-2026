#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int block_size = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File Null\n");
        return 1;
    }

    uint8_t buffer[block_size];
    int count = 0;
    char filename[8];
    FILE *img = NULL;
    while (fread(buffer, 1, block_size, card) == block_size)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            // else
            // fclose(filename);
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                return 1;
            }
            fwrite(buffer, 1, block_size, img);
            count++;
        }
        else
        {
            if (img != NULL)
                fwrite(buffer, 1, block_size, img);
        }
    }
    fclose(card);
    fclose(img);
}
