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

#define MAP_DEF(T, SUFFIX)\
   RB_TREE_NODE_DEF(T, SUFFIX)\
   RB_TREE_DEF(SUFFIX)\
   NEW_RB_TREE(SUFFIX)\
   NEW_RB_TREE_NODE(T, SUFFIX)\
   LEFT_ROTATE(SUFFIX)\
   RIGHT_ROTATE(SUFFIX)\
   RB_INSERT_FIXUP(SUFFIX)\

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
RB_TREE_NODE(SUFFIX) *dsc_new_rb_tree_node_##SUFFIX(T data, RB_TREE_NODE(SUFFIX) *nil){\
  Color color = BLACK;\
  RB_TREE_NODE(SUFFIX) *node = malloc(sizeof(RB_TREE_NODE(SUFFIX)));\
  node->left = nil;\
  node->right = nil;\
  node->parent = nil;\
  node->data = data;\
  node->color = color;\
}

#define NEW_RB_TREE(SUFFIX)\
RB_TREE(SUFFIX) *dsc_new_rb_tree_##SUFFIX(){\
  RB_TREE(SUFFIX) *tree = malloc(sizeof(RB_TREE(SUFFIX)));\
  tree->nil = malloc(sizeof(RB_TREE_NODE(SUFFIX)));\
  return tree;\
}

#define LEFT_ROTATE(SUFFIX)\
void dsc_left_rotate_##SUFFIX(RB_TREE(SUFFIX) *T, RB_TREE_NODE(SUFFIX) *x){\
  RB_TREE_NODE(SUFFIX) *y = x->left;\
  x->right = y->left;\
\
  if(y->left != T->nil){\
    y->left->parent = x;\
  }\
\
  y->parent = x->parent;\
\
  if(x->parent == T->nil){\
    T->root = y;\
  } else if(x == x->parent->left){\
    x->parent->left = y;\
  } else{\
    x->parent->right = y;\
  }\
\
  y->left = x;\
  x->parent = y;\
\
}

#define RIGHT_ROTATE(SUFFIX)\
void dsc_right_rotate_##SUFFIX(RB_TREE(SUFFIX) *T, RB_TREE_NODE(SUFFIX) *x){\
  RB_TREE_NODE(SUFFIX) *y = x->right;\
  x->left = y->right;\
\
  if(y->right != T->nil){\
    y->right->parent = x;\
  }\
\
  y->parent = x->parent;\
\
  if(x->parent == T->nil){\
    T->root = y;\
  } else if(x == x->parent->right){\
    x->parent->right = y;\
  } else{\
    x->parent->right = y;\
  }\
\
  y->right = x;\
  x->parent = y;\
}

#define RB_INSERT_FIXUP(SUFFIX)\
void dsc_rb_insert_fixup_##SUFFIX(RB_TREE(SUFFIX) *T, RB_TREE_NODE(SUFFIX) *z){\
  Color color;\
  while(z->parent->color == RED){\
    if(z->parent == z->parent->parent->left){\
      RB_TREE_NODE(SUFFIX) *y = z->parent->parent->right;\
      if(y->color == RED){\
        z->parent->color = BLACK;\
        y->color = BLACK;\
        z->parent->parent->color = RED;\
        z = z->parent->parent;\
      } else{\
        if(z == z->parent->right){\
          z = z->parent;\
          dsc_left_rotate_##SUFFIX(T, z);\
        }\
        z->parent->color = BLACK;\
        z->parent->parent->color = RED;\
        dsc_left_rotate_##SUFFIX(T, z->parent->parent); \
      }\
    } else{\
      RB_TREE_NODE(SUFFIX) *y = z->parent->parent->left;\
      if(y->color == RED){\
        z->parent->color = BLACK;\
        y->color = BLACK;\
        z->parent->parent->color = RED;\
        z->parent->parent;\
      } else{\
        if(z == z->parent->left){\
          z = z->parent;\
          dsc_right_rotate_##SUFFIX(T, z);\
        }\
        \
        z->parent->color = BLACK;\
        z->parent->parent->color = RED;\
        dsc_left_rotate_##SUFFIX(T, z->parent->parent);\
      }  \
    } \
  }\
T->root->color = BLACK;\
}
#endif // DSCLIB_IMPLEMENTATION
