#include <stdio.h>
#include "math_flp.h"

int main(void)
{
  double _sqroot, _cbroot, _nlog;
  _sqroot = sqroot(10);
  printf("Squre root of 10 is %.3f\n",_sqroot);
  printf("Squre of root 10 is %.3f\n",power(_sqroot,2));

  _cbroot = nthroot(10, 5, 0.0001);
  printf("Cube root of 10 is %.3f\n",_cbroot);
  printf("Cube of root 10 is %.3f\n",power(_cbroot,5));

  printf("Natural log of 0.5 is %.5f\n",natlog(0.5));
  printf("Natural log of 1.5 is %.5f\n",natlog(1.5));
  printf("Natural log of 10 is %.5f\n",natlog(10));

  printf("Large power of 2 for 9 is %d", msb(9));
  return 0;
}
