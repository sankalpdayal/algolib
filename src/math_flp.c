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


#define MINNUM 2.25e-308   // small number
#define MAXNUM 4E+168      // large number
#define NATLOG2 0.69314718 // natural log of 2

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
    } while (diff > MINNUM || diff < -MINNUM);
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

double natlog(double x)
/*computes natural log using multiple methods.
*x:input value for which natural log needs to be computed
*returns: natural log of given value x*/
{
  if (x <= 0) return -MAXNUM;
  if (x == 1) return 0;
  if (x < 1)
  /*use taylor series expansion*/
  {
    x = 1 - x;
    double y = -x, xpow = x, last, n = 1;
    while (n < 50){ //expand for 50 terms
      n++;
      xpow *= x;
      y -= xpow/n;
    }
    return y;
  }
  if (x < 2)
  /*use ramez function approximation. Should limit error to 0.00006*/
  {
    return -1.7417939 + (2.8212026 + (-1.4699568 + (0.44717955 - 0.056570851 * x) * x) * x) * x;
  }
  /*use smartly ramez function approximation. ln(x) = ln(2**n * x2)
  *ln(x) = n*ln(2)+ ln(x2), where x2 is between 1 and 2.*/
  double y, rem;
  int log2;
  log2 = msb(x);
  rem = x/(1<<log2);
  y = -1.7417939 + (2.8212026 + (-1.4699568 + (0.44717955 - 0.056570851 * rem) * rem) * rem) * rem;
  y += NATLOG2*log2;
  return y;
}

int msb(int x)
/*Fetches largest value of n for condition x > 2**n
*x:input number for which largest value of n is required
*returns largest value of n.*/
{
  int n=0;
  while(x >>= 1) n++;
  return n;
}
