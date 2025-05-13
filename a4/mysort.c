/*
--------------------------------------------------
Project: a4q1
File:    mysort.c
Author:  Zoya Adnan 
Version: 2025-02-07
--------------------------------------------------
*/

#include "mysort.h"

// swap pointers
void swap(void **x, void **y) {
     void *temp = *y;
     *y = *x;
     *x = temp;
}

// a compare floating values pointed by void pointers. 
int cmp(void *x, void *y) {
   float a = *(float*)x;
   float b = *(float*)y; 
     if (a > b) return 1;
     else if (a < b) return -1;
     else return 0;
}   

/**
 * Use selection sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers.
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void select_sort(void *a[], int left, int right) {
    for (int i = left; i<right; ++i) { // sorting through from left to right
        int k = i; // k is used to store the index of the smallest element found in the unsorted part of the list, starts with i


        for (int j = i + 1; j <= right; ++j) { // from 1 to right, responsible for finding the smallest element
            if (cmp (a[j], a[k]) <  0) { // if cmp returns less than 0, or --1, it means first one is smaller
                k = j; // we update k to j, meaning the smallest element is now at a[j]
            }
        }

        if (i != k) { // if this is true, means mmallest element is not at position i but instead is at position k. So, we need to swap a[i] and a[k]
            swap(&a[i], &a[k]); // preforms swap, use & because address needs to be changed too
        }

    }

}

/**
 * Use quick sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void quick_sort(void *a[], int left, int right) {
    if (left < right) { // ensures that the function only runs when there are at least two elements in the subarray
        int i = left + 1; // pivot is always a[left] so this is one after it
        int j = right; 

    while (i<= j) {
        while (i<= right && cmp ( a[i], a[left])<=0) // checking if element at a[i] is less or equal to pivot 
        i++; // Moves i to the right looking for an element greater than the pivot 

        while ( j >= left && cmp (a[j], a[left]) > 0) // checking if a[j] is move or equal to pivot
        j--; // Moves j to the left looking for an element less than or equal to the pivot 

        if ( i < j) { // if left element is bigger 
            swap(&a[i], &a[j]); // then swap 
        }

        swap(&a[left], &a[j]);
        quick_sort(a, left, j-1); // sort everything before j
        quick_sort(a, j+1, right); // sort everything after j 
    }
    }
}

/**
 * Use either selection or quick sort algorithm to sort array of pointers such that their pointed values 
 * are in order defined by the given comparison function
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) ) {
    if (left>= right) return;

    void *pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (cmp(a[j], pivot) < 0 ) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[right]);
    int pivot_index = i + 1;

    my_sort(a, left, pivot_index - 1, cmp);
    my_sort(a, pivot_index + 1, right, cmp);
}