#include <stdio.h>

#define DSCLIB_IMPLEMENTATION
#include "dsclib.h"

PAIR_DEF(int, int)
RB_TREE_NODE_DEF(PAIR(int, int), Pair)
RB_TREE_DEF(Pair)
NEW_RB_TREE(Pair)
NEW_RB_TREE_NODE(PAIR(int, int), Pair)

int main() {
  PAIR(int, int) p;
  RB_TREE(Pair) *root = dsc_new_rb_tree_Pair();
  p.first = 1;
  p.second = 2;


  printf("%d %d", p.first, p.second);
}
