/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {

    // your code here
    int number; 
    int total;

    while (scanf("%d", &number) == 1) { 
        total += number; 

    }

    return total; 

}
