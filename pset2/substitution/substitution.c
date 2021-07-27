#include <stdio.h>
#include <cs50.h> 
#include <ctype.h>
#include <string.h>

bool hasOnlyAlphaCharacters(string s)
{
    for (int i=0, n=strlen(s); i<n; i++)
    {
        if (!isalpha(s[i]))
            return false;
    }

    return true;
}

bool hasDuplicatedLetters(string s)
{
    int size = strlen(s);
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (s[i] == s[j])
                return true;
        }
    }

    return false;
}

string swapLettersByKey(string s, string key)
{
    for (int i=0, n=strlen(s); i<n; i++)
    {
        if (!isalpha(s[i]))
            continue;
        
        s[i] = isupper(s[i]) ? toupper(key[s[i]-65]) : tolower(key[s[i]-97]);
    }

    return s;
}

int main(int argc, string argv[])
{
    if (argc != 2 || !hasOnlyAlphaCharacters(argv[1]) || hasDuplicatedLetters(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    string plaintext = get_string("plaintext: ");
    string ciphertext = swapLettersByKey(plaintext, argv[1]);

    printf("ciphertext: %s\n", ciphertext);
    return 0;    
}