#include "spell.h"
#include "spell_lib.h"

int main(){

	//File handles
	FILE* input;
	FILE* dict;
	FILE* output = fopen("output.txt", "w");

	//arrays and variables to hold file paths and inputs
	char filename[100];
	char dictname[100];
	char** newDict;
	char word[30];
	char str[100];
	int line = 1;
	int badWord = 0;

	//prompting user for file
	do{
		printf("Enter file to open.\n");
		scanf("%s", filename);

		input = fopen(filename, "r");
	}while(input == NULL);

	//prompt user for dictionary
	do{
		printf("Enter dictionary to use.\n");
		scanf("%s", dictname);

		dict = fopen(dictname, "r");
	}while(dict == NULL);

	
	newDict = parseDict(dictname);

	//iterating through each line getting words and checking against dictionary
	while(fgets(str, 100, input) != NULL){

		//getting individual word length
		int wordLen = strcspn(str, " \0");

		//breaking the line into words
		char *token = strtok(str, " ");

		//getting remaining tokens
		while(token != NULL){

			//searching for word in dictionary
			int wordCheck = wordSearch(token, newDict);

			//checking is word was bad and printig to output.
			if(wordCheck == 0){
				
				bad_word(token, line, output);
				badWord++;
			}

			token = strtok(NULL, " ");
		}

		line++;
	}

	printf("%s %d %s", "This file had ", badWord, " misspelled word(s)" );

	fclose(input);
	fclose(output);
	fclose(dict);
}