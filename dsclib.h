#ifndef DSCLIB_INCLUDE_H
#define DSCLIB_INCLUDE_H

typedef enum Color{
  RED, BLACK
} Color;

#define PAIR(TYPE_FIRST, TYPE_SECOND) struct Pair_##TYPE_FIRST##_##TYPE_SECOND
#define RB_TREE_NODE(SUFFIX) struct Rb_Tree_Node_##SUFFIX
#define RB_TREE(SUFFIX) struct Rb_Tree_##SUFFIX
#define MAP(SUFFIX) RB_TREE(SUFFIX)
#define SET(SUFFIX) RB_TREE(SUFFIX)

#define RED 0
#define BLACK 1

#endif

#ifdef DSCLIB_IMPLEMENTATION
#include <stdlib.h>

#define PAIR_DEF(TYPE_FIRST, TYPE_SECOND)\
struct Pair_##TYPE_FIRST##_##TYPE_SECOND {\
  TYPE_FIRST first;\
  TYPE_SECOND second;\
};

#define RB_TREE_NODE_DEF(T, SUFFIX)\
struct Rb_Tree_Node_##SUFFIX{\
  RB_TREE_NODE(SUFFIX) *right;\
  RB_TREE_NODE(SUFFIX) *left;\
  RB_TREE_NODE(SUFFIX) *parent;\
  Color color;\
  T data;\
};

#define RB_TREE_DEF(SUFFIX)\
struct Rb_Tree_##SUFFIX{\
  RB_TREE_NODE(SUFFIX) *root;\
  RB_TREE_NODE(SUFFIX) *nil;\
};

#define NEW_RB_TREE_NODE(T, SUFFIX)\
RB_TREE_NODE(SUFFIX) *dsc_new_rb_tree_node_##SUFFIX(T data){\
  RB_TREE_NODE(SUFFIX) *node = malloc(sizeof(RB_TREE_NODE(SUFFIX)));\
  node->left = NULL;\
  node->right = NULL;\
  node->data = data;\
  node->color = BLACK;\
}

#define NEW_RB_TREE(SUFFIX)\
RB_TREE(SUFFIX) *dsc_new_rb_tree_##SUFFIX(){\
  RB_TREE(SUFFIX) *tree = malloc(sizeof(RB_TREE(SUFFIX)));\
  tree->nil = malloc(sizeof(RB_TREE_NODE(SUFFIX)));\
  return tree;\
}


#endif // DSCLIB_IMPLEMENTATION
