/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    int n1, n2, n3; 
    int total; 
    int count = 0; 

    printf("Enter three comma-separated integers: ");
  
    while (count == 0) { 
        if (scanf("%d,%d,%d", &n1, &n2, &n3) == 3) {
            total = n1 + n2 + n3; 
            count++; // Successfully got 3 integers, exit loop
        } else {
            printf("The integers were not properly entered. Please try again. \n");
            while (getchar() != '\n'); // clears the input buffer
        }
    }

    return total;
}
