/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {


    int num; 

    for (int i = 0; i < size; i++) {
        printf("Value for index %d\n", i);
        if (scanf("%d", &num) == 1) {
            array[i] = num; 
            while (getchar() != '\n');
        }
        else {
            printf("Not a valid integer");
            while (getchar() != '\n'); 
            i--;
        }
    }

    return; 

}
