#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

/* Binary Tree node structure */
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} TreeNode;

/* Binary Search Tree structure */
typedef struct {
    TreeNode *root;
    int size;
} Tree;

/* ===== Initialization and Memory Management ===== */
Tree* tree_create(void);
void tree_free(Tree *tree);
TreeNode* tree_node_create(int data);

/* ===== Basic Operations ===== */
void tree_insert(Tree *tree, int data);
int tree_contains(Tree *tree, int data);
void tree_delete(Tree *tree, int data);
int tree_find_min(Tree *tree);
int tree_find_max(Tree *tree);

/* ===== Utilities ===== */
int tree_is_empty(Tree *tree);
int tree_size(Tree *tree);
int tree_height(Tree *tree);
void tree_clear(Tree *tree);

/* ===== Traversal ===== */
void tree_inorder(Tree *tree);
void tree_preorder(Tree *tree);
void tree_postorder(Tree *tree);
void tree_levelorder(Tree *tree);

#endif
