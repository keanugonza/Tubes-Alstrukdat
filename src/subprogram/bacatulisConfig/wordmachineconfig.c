#include <stdio.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV_Char();
    }
}

void STARTWORD()
{
    START_Char();
    IgnoreBlanks();
    if (currentChar == MARKSC || currentChar == MARKNL)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARKSC || currentChar == MARKNL)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARKSC && currentChar != MARKNL)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV_Char();
        }
        else
            break;
    }
}

void STARTWORD_takeBlank()
{
    START_Char();
    while(currentChar == MARKNL) ADV_Char();
    CopyWord_takeBlank();
    ADV_Char();
}

void ADVWORD_takeBlank()
{   
    while(currentChar == MARKNL) ADV_Char();
    CopyWord_takeBlank();
    ADV_Char();
}

void CopyWord_takeBlank()
{
    currentWord.Length = 0;
    while (currentChar != MARKSC)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV_Char();
        }
        else
            break;
    }
}

void displayWord(Word w){
    int i;
    for(i = 0 ; i < w.Length ; i++){
        printf("%c",w.TabWord[i]);
    }
    fflush(stdout);
}

boolean isWordEqual(Word w1, Word w2){
    int i;
    if(w1.Length != w2.Length) return false;
    else{
        for(i = 0; i < w1.Length ; i++)
            if(w1.TabWord[i] != w2.TabWord[i]) return false;
    }
    return true;
}