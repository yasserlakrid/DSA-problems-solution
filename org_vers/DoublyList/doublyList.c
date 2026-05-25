#include "doublyList.h"

/* Create a new doubly linked list node */
DNode* dnode_create(int data) {
    DNode *node = (DNode *)malloc(sizeof(DNode));
    if (!node) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/* Create a new doubly linked list */
DoublyList* doublylist_create(void) {
    DoublyList *list = (DoublyList *)malloc(sizeof(DoublyList));
    if (!list) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/* Free doubly linked list memory */
void doublylist_free(DoublyList *list) {
    if (!list) return;
    
    DNode *current = list->head;
    while (current) {
        DNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

/* Insert data at front */
void doublylist_insert_front(DoublyList *list, int data) {
    if (!list) return;
    
    DNode *new_node = dnode_create(data);
    if (!new_node) return;
    
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

/* Insert data at end */
void doublylist_insert_end(DoublyList *list, int data) {
    if (!list) return;
    
    DNode *new_node = dnode_create(data);
    if (!new_node) return;
    
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

/* Insert data at specific index */
void doublylist_insert_at(DoublyList *list, int index, int data) {
    if (!list || index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }
    
    if (index == 0) {
        doublylist_insert_front(list, data);
        return;
    }
    
    if (index == list->size) {
        doublylist_insert_end(list, data);
        return;
    }
    
    DNode *new_node = dnode_create(data);
    if (!new_node) return;
    
    DNode *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    new_node->next = current->next;
    new_node->prev = current;
    current->next->prev = new_node;
    current->next = new_node;
    list->size++;
}

/* Remove front node */
void doublylist_remove_front(DoublyList *list) {
    if (!list || !list->head) return;
    
    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        DNode *temp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
    }
    list->size--;
}

/* Remove end node */
void doublylist_remove_end(DoublyList *list) {
    if (!list || !list->tail) return;
    
    if (list->head == list->tail) {
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
    } else {
        DNode *temp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
    }
    list->size--;
}

/* Remove node at specific index */
void doublylist_remove_at(DoublyList *list, int index) {
    if (!list || index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    
    if (index == 0) {
        doublylist_remove_front(list);
        return;
    }
    
    if (index == list->size - 1) {
        doublylist_remove_end(list);
        return;
    }
    
    DNode *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    list->size--;
}

/* Get data at index */
int doublylist_get(DoublyList *list, int index) {
    if (!list || index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return -1;
    }
    
    DNode *current;
    if (index < list->size / 2) {
        current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (int i = list->size - 1; i > index; i--) {
            current = current->prev;
        }
    }
    return current->data;
}

/* Find index of data */
int doublylist_find(DoublyList *list, int data) {
    if (!list) return -1;
    
    DNode *current = list->head;
    int index = 0;
    while (current) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

/* Check if list contains data */
int doublylist_contains(DoublyList *list, int data) {
    return doublylist_find(list, data) != -1;
}

/* Clear the doubly linked list */
void doublylist_clear(DoublyList *list) {
    if (!list) return;
    
    while (list->head) {
        DNode *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->tail = NULL;
    list->size = 0;
}

/* Check if list is empty */
int doublylist_is_empty(DoublyList *list) {
    return list && list->head == NULL;
}

/* Get list size */
int doublylist_size(DoublyList *list) {
    return list ? list->size : 0;
}

/* Reverse the doubly linked list */
void doublylist_reverse(DoublyList *list) {
    if (!list || list->size < 2) return;
    
    DNode *current = list->head;
    DNode *temp = NULL;
    
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

/* Compare function for sorting */
static int compare_nodes(const void *a, const void *b) {
    int val_a = *(int *)a;
    int val_b = *(int *)b;
    return val_a - val_b;
}

/* Sort the doubly linked list */
void doublylist_sort(DoublyList *list) {
    if (!list || list->size < 2) return;
    
    /* Create temporary array */
    int *arr = (int *)malloc(list->size * sizeof(int));
    if (!arr) return;
    
    /* Copy data to array */
    DNode *current = list->head;
    for (int i = 0; i < list->size; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    
    /* Sort array */
    qsort(arr, list->size, sizeof(int), compare_nodes);
    
    /* Copy sorted data back */
    current = list->head;
    for (int i = 0; i < list->size; i++) {
        current->data = arr[i];
        current = current->next;
    }
    
    free(arr);
}

/* Display doubly linked list forward */
void doublylist_display_forward(DoublyList *list) {
    if (!list) {
        printf("DoublyList is NULL\n");
        return;
    }
    
    printf("Forward: [");
    DNode *current = list->head;
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" <-> ");
        current = current->next;
    }
    printf("]\n");
}

/* Display doubly linked list backward */
void doublylist_display_backward(DoublyList *list) {
    if (!list) {
        printf("DoublyList is NULL\n");
        return;
    }
    
    printf("Backward: [");
    DNode *current = list->tail;
    while (current) {
        printf("%d", current->data);
        if (current->prev) printf(" <-> ");
        current = current->prev;
    }
    printf("]\n");
}
