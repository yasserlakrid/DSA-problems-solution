#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <stdio.h>
#include <stdlib.h>

/* Node structure for doubly linked list */
typedef struct dnode {
    int data;
    struct dnode *next;
    struct dnode *prev;
} DNode;

/* Doubly Linked List structure */
typedef struct {
    DNode *head;
    DNode *tail;
    int size;
} DoublyList;

/* ===== Initialization and Memory Management ===== */
DoublyList* doublylist_create(void);
void doublylist_free(DoublyList *list);
DNode* dnode_create(int data);

/* ===== Basic Operations ===== */
void doublylist_insert_front(DoublyList *list, int data);
void doublylist_insert_end(DoublyList *list, int data);
void doublylist_insert_at(DoublyList *list, int index, int data);
void doublylist_remove_front(DoublyList *list);
void doublylist_remove_end(DoublyList *list);
void doublylist_remove_at(DoublyList *list, int index);

/* ===== Search and Utilities ===== */
int doublylist_get(DoublyList *list, int index);
int doublylist_find(DoublyList *list, int data);
int doublylist_contains(DoublyList *list, int data);
void doublylist_clear(DoublyList *list);
int doublylist_is_empty(DoublyList *list);
int doublylist_size(DoublyList *list);

/* ===== Manipulation ===== */
void doublylist_reverse(DoublyList *list);
void doublylist_sort(DoublyList *list);

/* ===== Display ===== */
void doublylist_display_forward(DoublyList *list);
void doublylist_display_backward(DoublyList *list);

#endif
