#include <stdio.h>

#define DSCLIB_IMPLEMENTATION
#include "dsclib.h"

PAIR_DEF(int, int);

int main() {
  PAIR(int, int) p;
  p.first = 1;
  p.second = 2;


  printf("%d %d", p.first, p.second);
}
