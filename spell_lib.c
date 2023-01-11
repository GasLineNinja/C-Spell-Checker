#include "spell_lib.h"

char** parseDict(char* path){ 

	//variables of count of words
	int numWords = totalWords(path);

	//array to hold word for counting
	char word[30];

	//opening dictionary passed in
	FILE* dict = fopen(path, "r");
	
	//dynamically creating array for dictionary pointers
	char** newDict = malloc(numWords*sizeof(char*));

	//reading file 2nd time and changing all char to lowercse
	rewind(dict);
	int i = 0;
	while(!feof(dict)){
		fscanf(dict, "%s", word);

		//getting length of word
		int str = strcspn(word, "\0");

		//changing all characters to lowercase
		for(int j=0; j<str;j++){
			word[j] = tolower(word[j]);
		}
		
		//allocating size
        newDict[i] = malloc((str+1)*sizeof(char));

        //putting word into newDict
        strncpy(newDict[i], word, str);

        //printf("%s\n", newDict[i]);
		
	    i++; 
	 }
	//printf("%d\n", numWords);

	fclose(dict);
	return newDict;
}


int wordSearch(char* word, char** dict){
	int i=0;
	int comp;
	char newWord[30];
	char* dictWord;

	//getting just alpha characters from word to check against dictionary
	while(isalpha(word[i])){
		newWord[i] = word[i];
		i++;
	}

	//word now only contains lowercase letters
	word = lowerWord(newWord);

/********problem looping through dictionary entries*******/

	//looping through dict searching for word
	for(int j=0; j<sizeof(&dict); j++){
		comp = strncmp(word, *dict, strlen(word));

	// int j = 0;
	// while(dict[j]){
	// 	comp = strncmp(word, dict[j], strlen(word));
		
		//if word is found in dict return 1
		if(comp == 0){
			return 1;
		}

		//pointer arithmetic to move through array of dictionary entries
		dict++;
		//j++;
	}
	
/*********************************************************/

	//otherwise return 0
	return 0;
}


int bad_word(char* word, int line, FILE* out){
	
	if(out == NULL){
		return 1;
	}

	else{
		
	fprintf(out, "%s %s %s %d %s\n", "Unknown word", word ,"found in line", line, "of the input file.");

	return 0;
	}
}


char* lowerWord(char* word){

	//changing all characters to lowercase
	int  i= 0;
	while(isalpha(word[i])){
		word[i] = tolower(word[i]);
		i++;
	}

	return word;
}


int totalWords(char* path){
	//variables of count of words
	int numWords;

	//array to hold word for counting
	char word[30];

	//opening dictionary passed in
	FILE* dict = fopen(path, "r");

	//reading dictionary and counting words
	while(!feof(dict)){
		fscanf(dict, "%s", word);
		numWords++;
	}
	fclose(dict);

	return numWords;
}
	

