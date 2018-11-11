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

    // Validating key from command line input and storing in variable k
    string k = (argv[1]);
    int lengk = strlen(k);
    for (int i = 0; i < lengk; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Invalid key\n");
            return 1;
        }
    }

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
    for (int i = 0, index = 0; i < strlen(txt); i++)
    {
        // Get letter key
        int key = (k[index % lengk]);

        if (isupper(key))
        {
            key -= 65;
        }
        else if (islower(key))
        {
            key -= 97;
        }

        // For lower case letters
        if (islower(txt[i]) && isalpha(txt[i]))
        {
            txt[i] = ((txt[i] - 97 + key) % 26) + 97;
            printf("%c", txt[i]);

            // Only increase index if used
            index++;
        }
        // For upper case letters
        else if (isupper(txt[i]) && isalpha(txt[i]))
        {
            txt[i] = ((txt[i] - 65 + key) % 26) + 65;
            printf("%c", txt[i]);

            index++;
        }
        else
        {
            printf("%c", txt[i]);
        }
    }
    printf("\n");
    return 0;
}
