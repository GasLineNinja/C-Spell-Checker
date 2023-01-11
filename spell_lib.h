#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char** parseDict(char* path);

int wordSearch(char* word, char** dict);

int bad_word(char* word, int line, FILE* out);

char* lowerWord(char* word);

int totalWords(char* path);