/*
--------------------------------------------------
Project: a3q1
File:    mystring.c
Author:  Zoya Adnan
Version: 2025-01-31
--------------------------------------------------
*/

#include "mystring.h"


/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a string
 * @return - return the number of words.
 */

int str_words(char *s) {

	int count = 0; // Always initialize it to 0
	char *p = s; // So we dont lose address of s

	while (*p) {
		if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
			if (p == s || (*(p - 1) == ' ' || *(p - 1) == '\t' || *(p - 1) == ',' || *(p - 1) == '.')) { // checks if previous character was a delimter meaning this is now a new word (so count goes up) OR if its the very first letter 
				count++; 
			}
		}
		p++; 
	}
	
	return count;
}





/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 */

int str_lower(char *s) {
// your code

int count = 0; 
char *p = s; 

while (*p) {
	if (*p >= 'A' && *p <= 'Z') {
	*p = *p + 32; 
	count++;
	}
	p++; 
}

return count; 


}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */

 void str_trim(char *s) {
    char *p = s;  // Read pointer
    char *q = s;  // Write pointer

    // Step 1: Skip leading spaces
    while (*p == ' ') {
        p++;
    }

    // Step 2: Copy characters while removing extra spaces
    while (*p) {
        if (*p != ' ' || (p > s && *(p-1) != ' ')) {
            *q = *p;
            q++; // no * because we're jusst moving the pointer aka address is what we need not the value 
        }
        p++; 
    }

    if (q > s && (q-1) == ' ') { // checks if q has moved from start and if last character stored is space
        *(q-1) = '\0'; // if it is, it replaces it with a null terminator 
    }

    else {
        q = '\0';

    }
}
