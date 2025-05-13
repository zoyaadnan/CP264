/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {

    // your code here
    for (int i = 0; i < data->lines; i++) { 
        if (strlen(data->strings[i]) < length) {
            fprintf("%s\n", fp_short, data->strings[i]);
        }
        else {
            fprintf("%s\n", fp_long, data->strings[i]);
        }
    }
    return;
}
