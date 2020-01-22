#include <stdio.h>
#include "math_flp.h"

int main(void)
{
  double _sqroot, _cbroot;
  _sqroot = sqroot(10);
  printf("Squre root of 10 is %.3f\n",_sqroot);
  printf("Squre of root 10 is %.3f\n",_sqroot*_sqroot);

  _cbroot = cbroot(10);
  printf("Cube root of 10 is %.3f\n",_cbroot);
  printf("Cube of root 10 is %.3f\n",_cbroot*_cbroot*_cbroot);

  return 0;
}
