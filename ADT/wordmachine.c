#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK || currentChar == MARKSC || currentChar == MARKNL)
    {
        ADV_Char();
    }
}
void IgnoreNL()
{
    while (currentChar == MARKNL)
    {
        ADV_Char();
    }
}

void STARTWORD()
{
    START_Char();
    IgnoreBlanks();
    CopyWord();
}

void ADVWORD()
{
    IgnoreBlanks();
    CopyWord();
}

void CopyWord()
{
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARKSC && currentChar != MARKNL)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
        }
        ADV_Char();
    }
}

void STARTWORD_takeBlank()
{
    START_Char();
    while(currentChar == MARKSC || currentChar == MARKNL){
        ADV_Char();
    }
    CopyWord_takeBlank();
}

void ADVWORD_takeBlank()
{   
    while(currentChar == MARKSC || currentChar == MARKNL){
        ADV_Char();
    }
    CopyWord_takeBlank();
}

void CopyWord_takeBlank()
{
    currentWord.Length = 0;
    while (currentChar != MARKSC && currentChar != MARKNL)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
        }
        ADV_Char();
    }
}

void displayWord(Word w){
    int i;
    for(i = 0 ; i < w.Length ; i++){
        printf("%c",w.TabWord[i]);
    }
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


Word stringToWord(char* cstring){
    int i=0;
    Word res;
    res.Length = 0;
    while(cstring[i] != '\0'){
        res.TabWord[i] = cstring[i];
        res.Length++;
        i++;
    }
    return res;
}

int wordToInt(Word w){
    int i,res, peng;
    res = 0;
    i = 0;
    if(w.TabWord[i] == '-'){
        i++;
        peng = -1;
    }
    else peng = 1;
    for(i;i<w.Length;i++){
        res *=10;
        res += (int)(w.TabWord[i] - '0');
    }
    return res*peng;
}

char* wordToString(Word w){
    char *str = (char*)malloc(281);
    int i;
    for(i = 0; i < w.Length; i++){
        str[i] = w.TabWord[i];
    }
    str[i] = '\0';
    return str;
}

Word charToWord(char c){
    Word w;
    w.TabWord[0] = c;
    w.Length = 1;
    return w;
}