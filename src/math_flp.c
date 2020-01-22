/*====================================================================
This file containes floating point math functions writeen from scratch.
*Feel free to use it as you like. Do something good!
*
*Author: Sankalp Dayal
*email: sankalpdayal@gmail.com
*Version: 0.1
*Repo: https://github.com/sankalpdayal/algolib
====================================================================*/
#include "math_flp.h"


//#define MINDIFF 2.2250738585072014e-308   // smallest positive double
#define MINDIFF 2.25e-308                   // use for convergence check

double sqroot(double square)
/*computes square root using newton rhapson method
*square: value for which square root needs to be computed.
*returns: Square root*/
{
    double root=square/3, last, diff=1;
    if (square <= 0.0) return 0;
    do {
        last = root;
        root = (root + square / root) / 2; //update equation
        diff = root - last;
    } while (diff > MINDIFF || diff < -MINDIFF);
    return root;
}


double nthroot(double x, int n, double precision)
/*computes nth root using newton rhapson method
*x:input value for which n th root needs to be computed
*n: the nth root
*precision: to what precision the root should be accurate
returns: nth root for the given value x*/
{
    double root=x/3, last, diff=1;
    if (x <= 0.0) return 0;
    do {
        last = root;
        root = ((n-1)*root + x / power(root, n-1)) /n;//update equation
        diff = root - last;
    } while (diff > precision || diff < -precision);
    return root;
}


double power(double x, int n)
/*Computer nth power for number x
*x: Number for which n th power needs to be computed
*n: the n th power
returns: x to the power n*/
{
  if(n==0) return 1;
  if(n==1) return x;
  double y = 1;
  do {
    //TODO: Do something smart here.
    y *= x;
    n--;
  } while (n>0);
  return y;
}
