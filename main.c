#include <stdio.h>

#define DSCLIB_IMPLEMENTATION
#include "dsclib.h"

PAIR_DEF(int, char)

int compare_pairs(PAIR(int, char) a, PAIR(int, char) b) {
  if (a.first < b.first)
    return -1;
  if (a.first > b.first)
    return 1;
  return 0;
}

MAP_DEF(PAIR(int, char), IntStringMap, compare_pairs)

int main() {
  MAP(IntStringMap) *my_map = dsc_new_rb_tree_IntStringMap();
  PAIR(int, char) p = {1, 'a'};

  MAP_INSERT(IntStringMap, my_map, p);
  RB_TREE_NODE(IntStringMap) *node = MAP_SEARCH(IntStringMap, my_map, p);

  printf("%d %c ", node->data.first, node->data.second);
}
