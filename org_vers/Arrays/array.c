#include "array.h"

/* Create a new array with given capacity */
Array* array_create(int capacity) {
    Array *arr = (Array *)malloc(sizeof(Array));
    if (!arr) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    arr->data = (int *)malloc(capacity * sizeof(int));
    if (!arr->data) {
        printf("Memory allocation failed\n");
        free(arr);
        return NULL;
    }
    arr->capacity = capacity;
    arr->size = 0;
    return arr;
}

/* Free array memory */
void array_free(Array *arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}

/* Resize array capacity */
void array_resize(Array *arr, int new_capacity) {
    if (!arr || new_capacity <= 0) return;
    
    int *new_data = (int *)realloc(arr->data, new_capacity * sizeof(int));
    if (!new_data) {
        printf("Memory reallocation failed\n");
        return;
    }
    arr->data = new_data;
    arr->capacity = new_capacity;
    if (arr->size > new_capacity) {
        arr->size = new_capacity;
    }
}

/* Append value to end of array */
void array_append(Array *arr, int value) {
    if (!arr) return;
    
    if (arr->size >= arr->capacity) {
        array_resize(arr, arr->capacity * 2);
    }
    arr->data[arr->size++] = value;
}

/* Insert value at specific index */
void array_insert(Array *arr, int index, int value) {
    if (!arr || index < 0 || index > arr->size) {
        printf("Invalid index\n");
        return;
    }
    
    if (arr->size >= arr->capacity) {
        array_resize(arr, arr->capacity * 2);
    }
    
    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}

/* Remove element at index */
void array_remove(Array *arr, int index) {
    if (!arr || index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        return;
    }
    
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

/* Get value at index */
int array_get(Array *arr, int index) {
    if (!arr || index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        return -1;
    }
    return arr->data[index];
}

/* Set value at index */
void array_set(Array *arr, int index, int value) {
    if (!arr || index < 0 || index >= arr->size) {
        printf("Invalid index\n");
        return;
    }
    arr->data[index] = value;
}

/* Find index of value */
int array_find(Array *arr, int value) {
    if (!arr) return -1;
    
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == value) {
            return i;
        }
    }
    return -1;
}

/* Check if array contains value */
int array_contains(Array *arr, int value) {
    return array_find(arr, value) != -1;
}

/* Clear array */
void array_clear(Array *arr) {
    if (arr) {
        arr->size = 0;
    }
}

/* Check if array is empty */
int array_is_empty(Array *arr) {
    return arr && arr->size == 0;
}

/* Check if array is full */
int array_is_full(Array *arr) {
    return arr && arr->size >= arr->capacity;
}

/* Reverse array elements */
void array_reverse(Array *arr) {
    if (!arr) return;
    
    for (int i = 0; i < arr->size / 2; i++) {
        int temp = arr->data[i];
        arr->data[i] = arr->data[arr->size - 1 - i];
        arr->data[arr->size - 1 - i] = temp;
    }
}

/* Compare function for qsort (ascending) */
static int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Compare function for qsort (descending) */
static int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

/* Sort array in ascending order */
void array_sort(Array *arr) {
    if (!arr) return;
    qsort(arr->data, arr->size, sizeof(int), compare_asc);
}

/* Sort array in descending order */
void array_sort_descending(Array *arr) {
    if (!arr) return;
    qsort(arr->data, arr->size, sizeof(int), compare_desc);
}

/* Display entire array */
void array_display(Array *arr) {
    if (!arr) {
        printf("Array is NULL\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

/* Display range of array */
void array_display_range(Array *arr, int start, int end) {
    if (!arr || start < 0 || end >= arr->size || start > end) {
        printf("Invalid range\n");
        return;
    }
    
    printf("[");
    for (int i = start; i <= end; i++) {
        printf("%d", arr->data[i]);
        if (i < end) printf(", ");
    }
    printf("]\n");
}
