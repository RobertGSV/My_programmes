#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key_array = argv[1];

    //// ****** Validate all input ******

    //// CHECK COMMAND LINE ARGUMENTS

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n\n");
        return 1;
    }

    int length = strlen(argv[1]);

    //// CHECK LENGTH

    if (length != 26)
    {
        printf("Key must be 26 letters long\n");
        return 1;
    }
    //// CHECK FOR DUPLICATES

    for (int n = 0; n < length; n++)
    {
        char temp_char = (key_array[n]);
        int counter = 0;

        for (int p = 0; p < length; p++)
        {

            if (temp_char == key_array[p])
            {

                counter = counter + 1;

                if (counter > 1)
                {
                    printf("duplicate letters not permitted \n");
                    counter = 0;
                    return 1;
                }
            }
        }
    }

    //// CHECK THAT INPUT IS LETTERS ONly

    for (int q = 0; q < length; q++)
    {
        if ((key_array[q] >= 'A') && (key_array[q] <= 'Z'))
        {
            ;
        }
        else if ((key_array[q] >= 'a') && (key_array[q] <= 'z'))
        {
            ;
        }
        else
        {
            printf("You must enter Letters only\n\n");
            return 1;
        }
    }

    //// ****** end of validation  of KEY******

    char map_array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};

    int j = 0;
    int i = 0;
    int plain_len = 0;

    string plain_text = get_string("Enter plain text\n");

    plain_len = strlen(plain_text);

    char cypher_array[plain_len];

    ///  printf("plaintext:   \t%s\n", plain_text);

    for (i = 0; i < plain_len; i++)
    {
        for (j = 0; j < length; j++)
        {

            if (islower(plain_text[i]))
                {
                map_array[j] = tolower(map_array[j]);
                key_array[j] = tolower(key_array[j]);
                }
            if (isupper(plain_text[i]))
                {
                map_array[j] = toupper(map_array[j]);
                key_array[j] = toupper(key_array[j]);
                }
            if (plain_text[i]==map_array[j])
            {
                cypher_array[i]=key_array[j];
            }
            if ((isalpha(plain_text[i]))==0)
            {
                cypher_array[i]=plain_text[i];
            }

        } // end for j
    } // end for i

    cypher_array[plain_len] = '\0';

    printf("ciphertext:%s\n", cypher_array);

    return 0;
}
