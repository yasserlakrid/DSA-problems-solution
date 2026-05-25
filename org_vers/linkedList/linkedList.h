#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

/* Node structure for linked list */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Linked List structure */
typedef struct {
    Node *head;
    int size;
} LinkedList;

/* ===== Initialization and Memory Management ===== */
LinkedList* linkedlist_create(void);
void linkedlist_free(LinkedList *list);
Node* node_create(int data);

/* ===== Basic Operations ===== */
void linkedlist_insert_front(LinkedList *list, int data);
void linkedlist_insert_end(LinkedList *list, int data);
void linkedlist_insert_at(LinkedList *list, int index, int data);
void linkedlist_remove_front(LinkedList *list);
void linkedlist_remove_end(LinkedList *list);
void linkedlist_remove_at(LinkedList *list, int index);

/* ===== Search and Utilities ===== */
int linkedlist_get(LinkedList *list, int index);
int linkedlist_find(LinkedList *list, int data);
int linkedlist_contains(LinkedList *list, int data);
void linkedlist_clear(LinkedList *list);
int linkedlist_is_empty(LinkedList *list);
int linkedlist_size(LinkedList *list);

/* ===== Manipulation ===== */
void linkedlist_reverse(LinkedList *list);
void linkedlist_sort(LinkedList *list);

/* ===== Display ===== */
void linkedlist_display(LinkedList *list);
void linkedlist_display_reverse(LinkedList *list);

#endif
