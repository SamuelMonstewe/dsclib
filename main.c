#include <stdio.h>

#define DSCLIB_IMPLEMENTATION
#include "dsclib.h"

RB_TREE_NODE_DEF(int, Int)
RB_TREE_DEF(Int)
NEW_RB_TREE(Int)
NEW_RB_TREE_NODE(int, Int)

int main() {
  SET(Int) *root = dsc_new_rb_tree_Int();

}
