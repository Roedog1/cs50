#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    string k = (argv[1]);
    int lenk = strlen(k);
    for (int i = 0, n = lenk; i < n; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("invalid key\n");  
            return 1;
        }
          
    }
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                printf("%c", ((s[i] - 'a') +  toupper(k[j]) - 'A') % 26 + 'a');
            }
            else if (isupper(s[i]))
            {
                printf("%c", ((s[i] - 'A') + toupper(k[j]) - 'A') % 26 + 'A');
            }
         j = (j + 1) % lenk; //wrap around, count off function
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
