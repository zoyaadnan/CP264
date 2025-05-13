/*
--------------------------------------------------
Project: a1q2
File:    powersum.c
Author:  Zoya Adnan
Version: 2025-01-16
--------------------------------------------------
*/

#include "powersum.h"

/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n) {

    int p = 1; 
  

    for (int i = 0; i < n; i++) {
        int temp = p * b;
        if (temp/b != p) {
            return 1;
        }

        p = temp;  

    }

    return 0; 

}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n) {
    int p = 1; 

    if (power_overflow(b, n) == 0) {
        
        for (int i = 0; i < n; i++) {
            int temp = p * b; 
            p = temp;
            }
    }
    else {
        return 0; 
    }

    return p; 
}



/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n) {
    int sum = 0; 
    int p = 1; 
     if (power_overflow(b, n) == 0) {
        for (int i = 0; i <= n; i++) {
            sum += p;  
            p = p * b; 
            }
                 
     }

    else {
        return 0;
     }

    return sum; 
}
