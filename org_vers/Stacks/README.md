# Stack Library (stack.h / stack.c)

## Overview
LIFO (Last-In-First-Out) stack implementation using linked list approach.

## Structures
```c
typedef struct stack_node {
    int data;
    struct stack_node *next;
} StackNode;

typedef struct {
    StackNode *top;
    int size;
} Stack;
```

## Core Functions

### Initialization
- `Stack* stack_create(void)` - Create new stack
- `void stack_free(Stack *stack)` - Free all nodes

### Core Operations
- `void stack_push(Stack *stack, int data)` - Push element onto stack
- `int stack_pop(Stack *stack)` - Pop element from stack (returns -1 if empty)
- `int stack_peek(Stack *stack)` - View top element without removing (returns -1 if empty)

### Utilities
- `int stack_is_empty(Stack *stack)` - Check if stack is empty
- `int stack_size(Stack *stack)` - Get stack size
- `void stack_clear(Stack *stack)` - Remove all elements

### Display
- `void stack_display(Stack *stack)` - Display stack top to bottom

## Time Complexity
- Push: O(1)
- Pop: O(1)
- Peek: O(1)

## Example Usage
```c
#include "stack.h"

int main() {
    Stack *stack = stack_create();
    
    // Push elements
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);
    
    // Display
    stack_display(stack);  // [30 -> 20 -> 10]
    
    // Peek
    int top = stack_peek(stack);  // Returns 30
    
    // Pop
    int val = stack_pop(stack);   // Returns 30, stack now [20 -> 10]
    stack_display(stack);
    
    // Size
    int sz = stack_size(stack);   // Returns 2
    
    // Check empty
    int empty = stack_is_empty(stack);  // Returns 0 (false)
    
    // Clean up
    stack_free(stack);
    return 0;
}
```

## Common Applications
- Expression evaluation
- Function call stack
- Backtracking algorithms
- Undo/Redo functionality
