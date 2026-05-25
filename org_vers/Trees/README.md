# Binary Search Tree Library (tree.h / tree.c)

## Overview
Binary Search Tree implementation with full insertion, deletion, and traversal operations.

## Structures
```c
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} TreeNode;

typedef struct {
    TreeNode *root;
    int size;
} Tree;
```

## Core Functions

### Initialization
- `Tree* tree_create(void)` - Create new tree
- `void tree_free(Tree *tree)` - Free all nodes
- `TreeNode* tree_node_create(int data)` - Create new node

### Basic Operations
- `void tree_insert(Tree *tree, int data)` - Insert data maintaining BST property
- `void tree_delete(Tree *tree, int data)` - Delete node (handles all cases)
- `int tree_contains(Tree *tree, int data)` - Check if value exists
- `int tree_find_min(Tree *tree)` - Find minimum value
- `int tree_find_max(Tree *tree)` - Find maximum value

### Utilities
- `int tree_is_empty(Tree *tree)` - Check if tree is empty
- `int tree_size(Tree *tree)` - Get number of nodes
- `int tree_height(Tree *tree)` - Get tree height
- `void tree_clear(Tree *tree)` - Remove all nodes

### Traversal Methods
- `void tree_inorder(Tree *tree)` - In-order: Left-Node-Right (sorted)
- `void tree_preorder(Tree *tree)` - Pre-order: Node-Left-Right
- `void tree_postorder(Tree *tree)` - Post-order: Left-Right-Node
- `void tree_levelorder(Tree *tree)` - Level-order (BFS)

## Time Complexity (Average)
- Insert: O(log n)
- Delete: O(log n)
- Search: O(log n)
- Find Min/Max: O(log n)

## Example Usage
```c
#include "tree.h"

int main() {
    Tree *tree = tree_create();
    
    // Insert elements
    tree_insert(tree, 50);
    tree_insert(tree, 30);
    tree_insert(tree, 70);
    tree_insert(tree, 20);
    tree_insert(tree, 40);
    tree_insert(tree, 60);
    tree_insert(tree, 80);
    
    // Traversals
    tree_inorder(tree);     // Output: 20 30 40 50 60 70 80
    tree_preorder(tree);    // Output: 50 30 20 40 70 60 80
    tree_postorder(tree);   // Output: 20 40 30 60 80 70 50
    tree_levelorder(tree);  // Output: 50 30 70 20 40 60 80
    
    // Search
    int exists = tree_contains(tree, 40);  // Returns 1 (true)
    
    // Min/Max
    int min = tree_find_min(tree);  // Returns 20
    int max = tree_find_max(tree);  // Returns 80
    
    // Info
    int sz = tree_size(tree);       // Returns 7
    int ht = tree_height(tree);     // Returns 3
    
    // Delete
    tree_delete(tree, 30);
    tree_inorder(tree);  // 20 40 50 60 70 80
    
    // Clean up
    tree_free(tree);
    return 0;
}
```

## Common Applications
- Sorted data storage
- Range queries
- Autocomplete systems
- Expression parsing
