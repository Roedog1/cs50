#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", ((s[i] - 'a') + k)%26 + 'a');
        }
        else if (isupper(s[i]))
        {
            printf("%c", ((s[i] - 'A') + k)%26 + 'A');
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
