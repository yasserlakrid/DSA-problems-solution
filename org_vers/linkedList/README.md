# Linked List Library (linkedList.h / linkedList.c)

## Overview
Single linked list implementation with full node management and traversal capabilities.

## Structures
```c
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;
```

## Core Functions

### Initialization
- `LinkedList* linkedlist_create(void)` - Create new linked list
- `void linkedlist_free(LinkedList *list)` - Free all nodes
- `Node* node_create(int data)` - Create new node

### Basic Operations
- `void linkedlist_insert_front(LinkedList *list, int data)` - Insert at beginning
- `void linkedlist_insert_end(LinkedList *list, int data)` - Insert at end
- `void linkedlist_insert_at(LinkedList *list, int index, int data)` - Insert at index
- `void linkedlist_remove_front(LinkedList *list)` - Remove first node
- `void linkedlist_remove_end(LinkedList *list)` - Remove last node
- `void linkedlist_remove_at(LinkedList *list, int index)` - Remove at index

### Search & Utilities
- `int linkedlist_get(LinkedList *list, int index)` - Get value at index
- `int linkedlist_find(LinkedList *list, int data)` - Find index of value
- `int linkedlist_contains(LinkedList *list, int data)` - Check if contains value
- `int linkedlist_is_empty(LinkedList *list)` - Check if empty
- `int linkedlist_size(LinkedList *list)` - Get list size
- `void linkedlist_clear(LinkedList *list)` - Clear all nodes

### Manipulation
- `void linkedlist_reverse(LinkedList *list)` - Reverse the list
- `void linkedlist_sort(LinkedList *list)` - Sort in ascending order

### Display
- `void linkedlist_display(LinkedList *list)` - Display forward
- `void linkedlist_display_reverse(LinkedList *list)` - Display backward

## Example Usage
```c
#include "linkedList.h"

int main() {
    LinkedList *list = linkedlist_create();
    
    // Add elements
    linkedlist_insert_end(list, 10);
    linkedlist_insert_end(list, 20);
    linkedlist_insert_end(list, 30);
    linkedlist_insert_front(list, 5);
    
    // Display
    linkedlist_display(list);  // [5 -> 10 -> 20 -> 30]
    
    // Find and search
    int idx = linkedlist_find(list, 20);  // Returns 2
    int val = linkedlist_get(list, 1);    // Returns 10
    
    // Reverse
    linkedlist_reverse(list);
    linkedlist_display(list);  // [30 -> 20 -> 10 -> 5]
    
    // Clean up
    linkedlist_free(list);
    return 0;
}
```
