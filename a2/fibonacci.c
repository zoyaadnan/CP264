/*
--------------------------------------------------
Project: a2q1
File:    fibonacci.c
Author:  Zoya Adnan
Version: 2025-01-16
--------------------------------------------------
*/
#include "fibonacci.h"

/**
 * Cmpute and return the nth Fibonacci number F(n) using iterative algorithm, 
 *  namely using a for or while loop. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int iterative_fibonacci(int n) {
    int f1 = 0; 
    int f2 = 1; 
    int temp; 
    
    if (n == 0) {
        return 0; 
    }
    if (n == 1) {
        return 1; 
    }
    for (int i = 2; i <= n; i++) {
        temp = f2; 
        f2 = f1 + f2; 
        f1 = temp; 
    }

    return f2; 

}

/**
 * Cmpute and return the nth Fibonacci number F(n) using recurisve algorithm, 
 *  namely using recursion function. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n; 
    }

    else {
        return recursive_fibonacci(n-2) + recursive_fibonacci(n-1);
    }
}

/**
 * Cmpute and return the nth Fibonacci number F(n) using dynamic programming 
 * bottom-up method with external array f[n+1] of initial value -1 for all elements. 
 * Namely it fills up f[] byf[0]=0, f[1]=1, a[i]= a[i-2]+a[i-1] for i=2,...,n, and 
 * return f[n]. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int dpbu_fibonacci(int *f, int n) {
    f[0] = 0;
    f[1] = 1; 

    for (int i=2; i <= n; i++) {
        f[i] = f[i-2] + f[i-1];
    }
    return f[n];
}


/**
 * Cmpute and return the nth Fibonacci number F(n) using dynamic programming 
 * top-down method with external array f[n+1] of initial value -1 for all elements. 
 * Namely it fills up f[n+1] by recursion function call. Specifically it returns 
 * f[n] if f[n]>0 else sets f[n] = dptd_fibonacci(f, n-2) + dptd_fibonacci(f, n-1) 
 * and then returns f[n] 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number F(n).
 */
int dptd_fibonacci(int *f, int n) {
    if (n <= 1) {
        f[n] = n; 
        return n; 
    }
    else {
        f[n] = dptd_fibonacci(f, n-2) + dptd_fibonacci(f, n-1);
        return f[n];

    }
      
    }
