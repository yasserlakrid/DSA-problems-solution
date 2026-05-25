# Doubly Linked List Library (doublyList.h / doublyList.c)

## Overview
Doubly linked list implementation with forward and backward traversal.

## Structures
```c
typedef struct dnode {
    int data;
    struct dnode *next;
    struct dnode *prev;
} DNode;

typedef struct {
    DNode *head;
    DNode *tail;
    int size;
} DoublyList;
```

## Core Functions

### Initialization
- `DoublyList* doublylist_create(void)` - Create new doubly linked list
- `void doublylist_free(DoublyList *list)` - Free all nodes
- `DNode* dnode_create(int data)` - Create new node

### Basic Operations
- `void doublylist_insert_front(DoublyList *list, int data)` - Insert at beginning
- `void doublylist_insert_end(DoublyList *list, int data)` - Insert at end
- `void doublylist_insert_at(DoublyList *list, int index, int data)` - Insert at index
- `void doublylist_remove_front(DoublyList *list)` - Remove first node
- `void doublylist_remove_end(DoublyList *list)` - Remove last node
- `void doublylist_remove_at(DoublyList *list, int index)` - Remove at index

### Search & Utilities
- `int doublylist_get(DoublyList *list, int index)` - Get value at index (optimized)
- `int doublylist_find(DoublyList *list, int data)` - Find index of value
- `int doublylist_contains(DoublyList *list, int data)` - Check if contains value
- `int doublylist_is_empty(DoublyList *list)` - Check if empty
- `int doublylist_size(DoublyList *list)` - Get list size
- `void doublylist_clear(DoublyList *list)` - Clear all nodes

### Manipulation
- `void doublylist_reverse(DoublyList *list)` - Reverse the list
- `void doublylist_sort(DoublyList *list)` - Sort in ascending order

### Display
- `void doublylist_display_forward(DoublyList *list)` - Display forward
- `void doublylist_display_backward(DoublyList *list)` - Display backward

## Advantages
- Bidirectional traversal
- Efficient removal (no need to find predecessor)
- Better for applications needing reverse iteration

## Example Usage
```c
#include "doublyList.h"

int main() {
    DoublyList *list = doublylist_create();
    
    // Add elements
    doublylist_insert_end(list, 10);
    doublylist_insert_end(list, 20);
    doublylist_insert_end(list, 30);
    doublylist_insert_front(list, 5);
    
    // Display both directions
    doublylist_display_forward(list);   // Forward: [5 <-> 10 <-> 20 <-> 30]
    doublylist_display_backward(list);  // Backward: [30 <-> 20 <-> 10 <-> 5]
    
    // Get element (optimized)
    int val = doublylist_get(list, 2);  // Returns 20
    
    // Remove
    doublylist_remove_at(list, 1);
    doublylist_display_forward(list);  // [5 <-> 20 <-> 30]
    
    // Clean up
    doublylist_free(list);
    return 0;
}
```
