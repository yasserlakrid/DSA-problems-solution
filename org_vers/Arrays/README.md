# Array Library (array.h / array.c)

## Overview
Dynamic array implementation with automatic resizing and comprehensive manipulation functions.

## Structures
```c
typedef struct {
    int *data;      // Dynamic array data
    int size;       // Current number of elements
    int capacity;   // Total allocated space
} Array;
```

## Core Functions

### Initialization
- `Array* array_create(int capacity)` - Create new array with initial capacity
- `void array_free(Array *arr)` - Free array memory
- `void array_resize(Array *arr, int new_capacity)` - Resize array capacity

### Basic Operations
- `void array_append(Array *arr, int value)` - Add element to end
- `void array_insert(Array *arr, int index, int value)` - Insert at specific index
- `void array_remove(Array *arr, int index)` - Remove element at index
- `int array_get(Array *arr, int index)` - Get value at index
- `void array_set(Array *arr, int index, int value)` - Set value at index

### Search & Utilities
- `int array_find(Array *arr, int value)` - Find index of value
- `int array_contains(Array *arr, int value)` - Check if value exists
- `void array_clear(Array *arr)` - Clear all elements
- `int array_is_empty(Array *arr)` - Check if empty
- `int array_is_full(Array *arr)` - Check if full

### Manipulation
- `void array_reverse(Array *arr)` - Reverse array elements
- `void array_sort(Array *arr)` - Sort ascending
- `void array_sort_descending(Array *arr)` - Sort descending

### Display
- `void array_display(Array *arr)` - Display entire array
- `void array_display_range(Array *arr, int start, int end)` - Display range

## Example Usage
```c
#include "array.h"

int main() {
    // Create array with capacity 10
    Array *arr = array_create(10);
    
    // Add elements
    array_append(arr, 5);
    array_append(arr, 3);
    array_append(arr, 8);
    array_append(arr, 1);
    
    // Display
    array_display(arr);  // Output: [5, 3, 8, 1]
    
    // Sort
    array_sort(arr);
    array_display(arr);  // Output: [1, 3, 5, 8]
    
    // Find
    int idx = array_find(arr, 5);  // Returns 2
    
    // Clean up
    array_free(arr);
    return 0;
}
```
