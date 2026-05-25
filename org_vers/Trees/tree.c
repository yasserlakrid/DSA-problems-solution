#include "tree.h"

/* Create a new tree node */
TreeNode* tree_node_create(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (!node) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Create a new tree */
Tree* tree_create(void) {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    if (!tree) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

/* Helper function to free tree nodes recursively */
static void tree_free_helper(TreeNode *node) {
    if (!node) return;
    tree_free_helper(node->left);
    tree_free_helper(node->right);
    free(node);
}

/* Free tree memory */
void tree_free(Tree *tree) {
    if (!tree) return;
    tree_free_helper(tree->root);
    free(tree);
}

/* Helper function to insert node recursively */
static TreeNode* insert_helper(TreeNode *node, int data, Tree *tree) {
    if (node == NULL) {
        tree->size++;
        return tree_node_create(data);
    }
    
    if (data < node->data) {
        node->left = insert_helper(node->left, data, tree);
    } else if (data > node->data) {
        node->right = insert_helper(node->right, data, tree);
    }
    
    return node;
}

/* Insert data into tree */
void tree_insert(Tree *tree, int data) {
    if (!tree) return;
    tree->root = insert_helper(tree->root, data, tree);
}

/* Helper function to find node recursively */
static TreeNode* find_helper(TreeNode *node, int data) {
    if (!node) return NULL;
    
    if (data == node->data) {
        return node;
    } else if (data < node->data) {
        return find_helper(node->left, data);
    } else {
        return find_helper(node->right, data);
    }
}

/* Check if tree contains data */
int tree_contains(Tree *tree, int data) {
    if (!tree) return 0;
    return find_helper(tree->root, data) != NULL;
}

/* Helper function to find minimum value */
static TreeNode* find_min_helper(TreeNode *node) {
    if (!node) return NULL;
    while (node->left) {
        node = node->left;
    }
    return node;
}

/* Find minimum value in tree */
int tree_find_min(Tree *tree) {
    if (!tree || !tree->root) {
        printf("Tree is empty\n");
        return -1;
    }
    return find_min_helper(tree->root)->data;
}

/* Helper function to find maximum value */
static TreeNode* find_max_helper(TreeNode *node) {
    if (!node) return NULL;
    while (node->right) {
        node = node->right;
    }
    return node;
}

/* Find maximum value in tree */
int tree_find_max(Tree *tree) {
    if (!tree || !tree->root) {
        printf("Tree is empty\n");
        return -1;
    }
    return find_max_helper(tree->root)->data;
}

/* Helper function to delete node recursively */
static TreeNode* delete_helper(TreeNode *node, int data, Tree *tree) {
    if (!node) return NULL;
    
    if (data < node->data) {
        node->left = delete_helper(node->left, data, tree);
    } else if (data > node->data) {
        node->right = delete_helper(node->right, data, tree);
    } else {
        /* Node found */
        tree->size--;
        
        /* Case 1: Leaf node */
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        
        /* Case 2: One child */
        if (node->left == NULL) {
            TreeNode *temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL) {
            TreeNode *temp = node->left;
            free(node);
            return temp;
        }
        
        /* Case 3: Two children */
        TreeNode *min_right = find_min_helper(node->right);
        node->data = min_right->data;
        node->right = delete_helper(node->right, min_right->data, tree);
    }
    
    return node;
}

/* Delete data from tree */
void tree_delete(Tree *tree, int data) {
    if (!tree) return;
    tree->root = delete_helper(tree->root, data, tree);
}

/* Check if tree is empty */
int tree_is_empty(Tree *tree) {
    return tree && tree->root == NULL;
}

/* Get tree size */
int tree_size(Tree *tree) {
    return tree ? tree->size : 0;
}

/* Helper function to calculate height */
static int height_helper(TreeNode *node) {
    if (!node) return 0;
    
    int left_height = height_helper(node->left);
    int right_height = height_helper(node->right);
    
    return 1 + (left_height > right_height ? left_height : right_height);
}

/* Get tree height */
int tree_height(Tree *tree) {
    if (!tree) return 0;
    return height_helper(tree->root);
}

/* Clear the tree */
void tree_clear(Tree *tree) {
    if (!tree) return;
    tree_free_helper(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

/* Helper function for inorder traversal (LNR) */
static void inorder_helper(TreeNode *node) {
    if (!node) return;
    inorder_helper(node->left);
    printf("%d ", node->data);
    inorder_helper(node->right);
}

/* Inorder traversal */
void tree_inorder(Tree *tree) {
    if (!tree) {
        printf("Tree is NULL\n");
        return;
    }
    printf("Inorder: ");
    inorder_helper(tree->root);
    printf("\n");
}

/* Helper function for preorder traversal (NLR) */
static void preorder_helper(TreeNode *node) {
    if (!node) return;
    printf("%d ", node->data);
    preorder_helper(node->left);
    preorder_helper(node->right);
}

/* Preorder traversal */
void tree_preorder(Tree *tree) {
    if (!tree) {
        printf("Tree is NULL\n");
        return;
    }
    printf("Preorder: ");
    preorder_helper(tree->root);
    printf("\n");
}

/* Helper function for postorder traversal (LRN) */
static void postorder_helper(TreeNode *node) {
    if (!node) return;
    postorder_helper(node->left);
    postorder_helper(node->right);
    printf("%d ", node->data);
}

/* Postorder traversal */
void tree_postorder(Tree *tree) {
    if (!tree) {
        printf("Tree is NULL\n");
        return;
    }
    printf("Postorder: ");
    postorder_helper(tree->root);
    printf("\n");
}

/* Helper function for level order traversal using queue */
typedef struct queue_node {
    TreeNode *tree_node;
    struct queue_node *next;
} QNode;

/* Level order traversal */
void tree_levelorder(Tree *tree) {
    if (!tree || !tree->root) {
        printf("Tree is empty\n");
        return;
    }
    
    printf("Level Order: ");
    
    QNode *queue_front = NULL;
    QNode *queue_rear = NULL;
    
    /* Enqueue root */
    QNode *q_node = (QNode *)malloc(sizeof(QNode));
    q_node->tree_node = tree->root;
    q_node->next = NULL;
    queue_front = q_node;
    queue_rear = q_node;
    
    /* Process queue */
    while (queue_front) {
        TreeNode *current = queue_front->tree_node;
        printf("%d ", current->data);
        
        if (current->left) {
            QNode *new_q_node = (QNode *)malloc(sizeof(QNode));
            new_q_node->tree_node = current->left;
            new_q_node->next = NULL;
            queue_rear->next = new_q_node;
            queue_rear = new_q_node;
        }
        
        if (current->right) {
            QNode *new_q_node = (QNode *)malloc(sizeof(QNode));
            new_q_node->tree_node = current->right;
            new_q_node->next = NULL;
            queue_rear->next = new_q_node;
            queue_rear = new_q_node;
        }
        
        QNode *temp = queue_front;
        queue_front = queue_front->next;
        free(temp);
    }
    printf("\n");
}
