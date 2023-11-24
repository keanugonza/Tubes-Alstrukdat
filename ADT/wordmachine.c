#include <stdio.h>
#include <stdlib.h>
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

void STARTREADCONFIG(Word w){
    START_Char_Config(w);
    IgnoreBlanks();
    CopyWord();
}

void ADVWORD()
{
    if(currentChar == MARKNL) ADV_Char();
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
    if(currentChar == MARKSC) ADV_Char();
}

void STARTWORD_takeBlank()
{
    START_Char();
    CopyWord_takeBlank();
}
void STARTREADCONFIG_takeBlank(Word w)
{
    START_Char_Config(w);
    CopyWord_takeBlank();
}

void ADVWORD_takeBlank()
{ 
    IgnoreBlanks(); 
    if(currentChar == MARKNL) ADV_Char();
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
    if(currentChar == MARKSC) ADV_Char();
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

DATETIME wordToDATETIME(Word w){
    DATETIME out;
    Word temp;
    int tempInt;
    temp.Length = 2;
    temp.TabWord[0] = w.TabWord[0]; // hari
    temp.TabWord[1] = w.TabWord[1];
    tempInt = wordToInt(temp);
    DAY(out) = tempInt;
    temp.Length = 2;
    temp.TabWord[0] = w.TabWord[3]; // bulan
    temp.TabWord[1] = w.TabWord[4];
    tempInt = wordToInt(temp);
    MONTH(out) = tempInt;
    temp.Length = 4;
    temp.TabWord[0] = w.TabWord[6]; // year
    temp.TabWord[1] = w.TabWord[7];
    temp.TabWord[2] = w.TabWord[8];
    temp.TabWord[3] = w.TabWord[9];
    tempInt = wordToInt(temp);
    YEAR(out) = tempInt;

    temp.Length = 2;
    temp.TabWord[0] = w.TabWord[11]; // jam
    temp.TabWord[1] = w.TabWord[12];
    tempInt = wordToInt(temp);
    HOUR(out) = tempInt;
    temp.Length = 2;
    temp.TabWord[0] = w.TabWord[14]; // menit
    temp.TabWord[1] = w.TabWord[15];
    tempInt = wordToInt(temp);
    MINUTE(out) = tempInt;
    temp.Length = 2;
    temp.TabWord[0] = w.TabWord[17]; // detik
    temp.TabWord[1] = w.TabWord[18];
    tempInt = wordToInt(temp);
    SECOND(out) = tempInt;
    return out;
}

Word concateWord(Word w1, Word w2){
    Word result;
    int i = 0;

    for (i = 0; i < w1.Length; i++) {
        result.TabWord[i] = w1.TabWord[i];
    }

    for (int j = 0; j < w2.Length && i < sizeof(result.TabWord) - 1; j++, i++) {
        result.TabWord[i] = w2.TabWord[j];
    }

    result.TabWord[i] = '\0';
    result.Length = i;

    return result;
}
