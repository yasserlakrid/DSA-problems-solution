#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

/* Array structure with metadata */
typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

/* ===== Initialization and Memory Management ===== */
Array* array_create(int capacity);
void array_free(Array *arr);
void array_resize(Array *arr, int new_capacity);

/* ===== Basic Operations ===== */
void array_insert(Array *arr, int index, int value);
void array_append(Array *arr, int value);
void array_remove(Array *arr, int index);
int array_get(Array *arr, int index);
void array_set(Array *arr, int index, int value);

/* ===== Search and Utilities ===== */
int array_find(Array *arr, int value);
int array_contains(Array *arr, int value);
void array_clear(Array *arr);
int array_is_empty(Array *arr);
int array_is_full(Array *arr);

/* ===== Sorting and Manipulation ===== */
void array_reverse(Array *arr);
void array_sort(Array *arr);
void array_sort_descending(Array *arr);

/* ===== Display ===== */
void array_display(Array *arr);
void array_display_range(Array *arr, int start, int end);

#endif
