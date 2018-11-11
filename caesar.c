#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // If command line input is incorrect
    if (argc != 2)
    {
        printf("Key?\n");
        return 1;
    }
    else
    {
        // Getting key from command line input and converting from string to integer
        int k = atoi(argv[1]);

        //   printf("%i\n", k);


        // Getting user input
        string txt;
        do
        {
            txt = get_string("plaintext:  ");
        }
        while (txt == 0);

        printf("ciphertext: ");
        // Start loop for number of letters in plaintext
        for (int i = 0; i < strlen(txt); i++)
        {
            // For lower case letters
            if (islower(txt[i]) && isalpha(txt[i]))
            {
                txt[i] = ((txt[i] - 97 + k) % 26) + 97;
                printf("%c", txt[i]);
            }

            // For upper case letters
            else if (isupper(txt[i]) && isalpha(txt[i]))
            {
                txt[i] = ((txt[i] - 65 + k) % 26) + 65;
                printf("%c",txt[i]);
            }
            else
            {
                printf("%c", txt[i]);
            }
        }
        printf("\n");
    }

    return 0;

}
