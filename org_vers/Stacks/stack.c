#include "stack.h"

/* Create a new stack */
Stack* stack_create(void) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

/* Free stack memory */
void stack_free(Stack *stack) {
    if (!stack) return;
    
    while (stack->top) {
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}

/* Push element onto stack */
void stack_push(Stack *stack, int data) {
    if (!stack) return;
    
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

/* Pop element from stack */
int stack_pop(Stack *stack) {
    if (!stack || !stack->top) {
        printf("Stack is empty\n");
        return -1;
    }
    
    StackNode *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    
    return data;
}

/* Peek at top element */
int stack_peek(Stack *stack) {
    if (!stack || !stack->top) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

/* Check if stack is empty */
int stack_is_empty(Stack *stack) {
    return stack && stack->top == NULL;
}

/* Get stack size */
int stack_size(Stack *stack) {
    return stack ? stack->size : 0;
}

/* Clear the stack */
void stack_clear(Stack *stack) {
    if (!stack) return;
    
    while (stack->top) {
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->size = 0;
}

/* Display stack from top to bottom */
void stack_display(Stack *stack) {
    if (!stack) {
        printf("Stack is NULL\n");
        return;
    }
    
    if (stack->top == NULL) {
        printf("Stack is empty []\n");
        return;
    }
    
    printf("Stack (top -> bottom): [");
    StackNode *current = stack->top;
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" -> ");
        current = current->next;
    }
    printf("]\n");
}
