#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{   //ensure user type in one comment argument
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./recover image\n");
        return 1;
    }
    // open input card file
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

    // read in 512 block of the image
    while (fread(buffer, 1, 512, inptr)!= 0x00)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // check if we found the beginning of a JPEG
        {
            if (outptr != NULL) // found another JPEG then close the previous file
            {
                fclose(outptr);
                imagecounter++;
            }
            // if we found JPEG, open new image file for writing
            sprintf(filename, "%03i.jpg", imagecounter);
            outptr = fopen(filename, "w");

        }
        if (outptr != NULL) // write to image file
        {
            fwrite(buffer, 1, 512, outptr);

        }
    }

    // close the last JPEG image file
    fclose(outptr);

    // close the input card.raw file
    fclose(inptr);

    return 0;
}





