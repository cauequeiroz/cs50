#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool hasOnlyDigits(string s)
{
    for (int i=0, n=strlen(s); i<n; i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

string shiftByKey(string s, int key)
{
    for (int i=0, n=strlen(s); i<n; i++)
    {
        if (!isalpha(s[i]))
            continue;

        int C_MIN = isupper(s[i]) ? 64 : 96;
        int C_MAX = isupper(s[i]) ? 90 : 122;
        int letter = (int) s[i];
        key = (key % 26);

        if (letter + key <= C_MAX)
        {
            s[i] = (char) (letter + key);
        }
        else
        {
            int remainder = C_MAX - letter;
            s[i] = (char) (C_MIN + (key - remainder));
        }
    }

    return s;
}

int main(int argc, string argv[])
{
    if (argc != 2 || !hasOnlyDigits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = shiftByKey(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}