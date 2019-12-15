#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./recover image\n");
        return 1;
    }

    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "File Not Found!\n");
        return 2;
    }

    BYTE buffer[512];
    int imagecounter = 0;
    char filename[8];
    FILE *outptr = NULL;

    while (fread(buffer, 512, 1, outptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
                imagecounter++;
            }

            sprintf(filename, "%03i.jpg", imagecounter);
            outptr = fopen(filename, "w");
        }
        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);

        }
    }

    fclose(outptr);

    fclose(inptr);

    return 0;
}





