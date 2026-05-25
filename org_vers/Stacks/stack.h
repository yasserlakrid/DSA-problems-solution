#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/* Stack node structure */
typedef struct stack_node {
    int data;
    struct stack_node *next;
} StackNode;

/* Stack structure */
typedef struct {
    StackNode *top;
    int size;
} Stack;

/* ===== Initialization and Memory Management ===== */
Stack* stack_create(void);
void stack_free(Stack *stack);

/* ===== Core Operations ===== */
void stack_push(Stack *stack, int data);
int stack_pop(Stack *stack);
int stack_peek(Stack *stack);

/* ===== Utilities ===== */
int stack_is_empty(Stack *stack);
int stack_size(Stack *stack);
void stack_clear(Stack *stack);

/* ===== Display ===== */
void stack_display(Stack *stack);

#endif
