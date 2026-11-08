#ifndef DSCLIB_INCLUDE_H
#define DSCLIB_INCLUDE_H

typedef enum Color{
  RED, BLACK
} Color;

#define PAIR(TYPE_FIRST, TYPE_SECOND) struct Pair_##TYPE_FIRST##_##TYPE_SECOND
#define RB_TREE_NODE(SUFFIX) struct Rb_Tree_Node_##SUFFIX
#define RB_TREE(SUFFIX) struct Rb_Tree_##SUFFIX
#endif

#ifdef DSCLIB_IMPLEMENTATION
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
};

#define NEW_RB_TREE_NODE(T, SUFFIX)
Rb_Tree_Node_##SUFFIX dsclib_new_rb_tree_node_##SUFFIX(T data){
  
}

#endif // DSCLIB_IMPLEMENTATION
