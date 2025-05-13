/*
--------------------------------------------------
Project: a2q2
File:    polynomial.c
Author:  Zoya Adnan
Version: 2025-01-16
--------------------------------------------------
*/

#include <stdio.h>
#include "polynomial.h"
#include <math.h>
#define EPSILON 1e-6
#define MAXCOUNT 100

/**
 * Cmpute and return the value of the (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (https://en.wikipedia.org/wiki/Horner%27s_method)
 *
 * @param *p - pointer to float number array
 * @param n  - the number of coefficients   
 * @return - the value of the above polynomial 
 */
float horner(float *p, int n, float x) {
    float r = 0; 
    int i; 
    for (i = 0; i < n; i++) {
        r = r * x + p[i];
    }
    return r; 

}

/**
 * Cmpute the derivative of input (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0 
 * output the coefficients of the derivative polynomial in an array. 
 * The derivative of the above polynomial p(x) is as follows.  
 * p'(x) = (n-1)* p[0]*x^{n-2} +  (n-2)*p[1]*x^{n-3} +...+ p[n-2]*x^0
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param *d - pointer to coefficient array of output polynomial. 
 * @param n  - the number of coefficients of the input polynomial
 */
void derivative(float *p, float *d, int n) {
    int i; 
    for (i = 0; i < n-1; i++) {
        d[i] = (n - 1 - i) * p[i];
}
}

/**
 * Compute approximate real root x of polynomial p(x) using Newton's 
 * method(https://en.wikipedia.org/wiki/Newton%27s_method).  
 * Use fault tolerant 1e-6 (or 0.000001) and maximum 100 iterations.
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param n  - the number of coefficients of the input polynomial
 * @param x0 - start point for Newton method
 * @return -  the root if found, otherwise x0.
 */
float newton(float *p, int n, float x0) {

    float d[n - 1];
    float x = x0;
    float sol, derSol;

    derivative(p, d, n);

    for (int i = 0; i < MAXCOUNT; i++) {
        x0 = x;

        sol = horner(p, n, x);
        derSol = horner(d, n - 1, x);

        if (fabs(derSol) < EPSILON) {
            return x;
        }

        x = x0 - (sol / derSol);

        if (fabs(x - x0) < EPSILON) {
            return x;
        }
    }

    return x;
}