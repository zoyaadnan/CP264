/*
--------------------------------------------------
Project: a1q1
File:    mychar.c
Author:  Zoya Adnan
Version: 2025-01-16
--------------------------------------------------
*/


/**
 * Determine the type of a char character.
 *
 * @param c - char type
 * @return - 0 if c is a digit 
             1 if c is an arithmetic operator
             2 if c is the left parenthsis (
             3 if c is the right parenthsis )
             4 if c is an English letter; 
             otherwise -1.
 */

#include "mychar.h"

int mytype(char c) {

    int answer; 

    if (c >= '0' && c <= '9') { 
        answer = 0;
    } else if (c == '+' || c == '-' || c == '*' || c == '%' || c == '/') { 
        answer = 1; 
    } else if (c == '(') { 
        answer = 2;
    } else if (c == ')') { 
        answer = 3;
    } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { 
        answer = 4; 
    } else { 
        answer = -1;
    }
    return answer; 
}

/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c) {

    if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }
    else if (c >= 'A' && c <= 'a') {
        c = c + 32; 

    }
    return c;
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c) {
    int value; 
    if (c >= '0' && c <= '9') {
        value = c - '0';
    }
    else {
        value = -1;
    }

    return value; 
}
