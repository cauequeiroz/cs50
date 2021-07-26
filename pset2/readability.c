#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float getAverageBy100(int x, int y)
{
    return ( x * 100 ) / (float) y;
}

int main(void)
{
    string text = get_string("Text: ");
    int numberOfLetters = 0;
    int numberOfWords = 1;
    int numberOfSentences = 0;


    for (int i=0, n=strlen(text); i<n; i++)
    {
        char letter = text[i];
        bool isLowerCaseCharacter = letter >= 97 && letter <= 122;
        bool isUpperCaseCharacter = letter >= 65 && letter <= 90;
        bool isSpaceCharacter = letter == 32;
        bool isEndOfSentenceCharacter = letter == 33 || letter == 46 || letter == 63;

        if (isLowerCaseCharacter || isUpperCaseCharacter)
        {
            numberOfLetters += 1;
        }
        else if (isSpaceCharacter)
        {
            numberOfWords += 1;
        }
        else if (isEndOfSentenceCharacter)
        {
            numberOfSentences += 1;
        }
    }

    float lettersByWords = getAverageBy100(numberOfLetters, numberOfWords);
    float sentencesByWords = getAverageBy100(numberOfSentences, numberOfWords);
    int index = (int) round(0.0588 * lettersByWords - 0.296 * sentencesByWords - 15.8);

    if (index < 1)    
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}