/*
--------------------------------------------------
Project: a3q2
File:    myword.c
Author:  Zoya Adnan
Version: 2025-01-31
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000


/*
 * Load word data from file, and insert words a directory represented by char array.
 *
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored.
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.
 */

int create_dictionary(FILE *fp, char *dictionary) {
	char line[1000]; // max characters line can hold 
	char delimiters = " .,\n\t\r"; 
	char *token;
	int count = 0; 

	while (fgets(line, 1000, fp) != NULL) { // reads single line from file and stores in line array 
		count++; 
		token = (char*) strtok(line, delimiters); //strtok used to split string into smaller pieces based on delimiters. here it splits and returns first token. check line 40.

		while (token != NULL) { // if theres no more tokens strtok returns NULL 
			strcat(dictionary, token); // token contains word from strtok, this line adds this word to end of dictionary 
			strcat(dictionary, ","); // adds a comma (",") after each word to separate them
			token = (char*) strtok(NULL, delimiters); //  tells strtok to continue splitting the same string, finding the next token

		}
	}

	return count; 

	}
/*
 * Determine if a given word is contained in the given dictionary.
 *
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.
 *
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.
 */

BOOLEAN contain_word(char *dictionary, char *word) {
	if (word == NULL || *word == '\0') return 0; // if empty return false 
	else {
		char temp[20] = {0}; 
		strcat(temp, ","); // adds a leading comma to temp 
		strcat(temp, word); // appends word to temp so temp has ",word"
		strcat(temp, ","); // adds trailing comma making temp contain ",word,"

		if (strstr(dictionary, temp) != NULL) { // checks if dictionary has temp 
			return TRUE; 
		}

		else {
			return FALSE; 
		}
		

	}




	}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.
 *
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.
 *
 * @return - WORDSTATS value of processed word stats information.
 */

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
// your code

	}