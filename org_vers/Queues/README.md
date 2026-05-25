# Queue Library (queue.h / queue.c)

## Overview
FIFO (First-In-First-Out) queue implementation using linked list approach.

## Structures
```c
typedef struct queue_node {
    int data;
    struct queue_node *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;
```

## Core Functions

### Initialization
- `Queue* queue_create(void)` - Create new queue
- `void queue_free(Queue *queue)` - Free all nodes

### Core Operations
- `void queue_enqueue(Queue *queue, int data)` - Add element to rear
- `int queue_dequeue(Queue *queue)` - Remove element from front (returns -1 if empty)
- `int queue_peek_front(Queue *queue)` - View front element (returns -1 if empty)
- `int queue_peek_rear(Queue *queue)` - View rear element (returns -1 if empty)

### Utilities
- `int queue_is_empty(Queue *queue)` - Check if queue is empty
- `int queue_size(Queue *queue)` - Get queue size
- `void queue_clear(Queue *queue)` - Remove all elements

### Display
- `void queue_display(Queue *queue)` - Display queue front to rear

## Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

## Example Usage
```c
#include "queue.h"

int main() {
    Queue *queue = queue_create();
    
    // Enqueue elements
    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    queue_enqueue(queue, 30);
    
    // Display
    queue_display(queue);  // [10 -> 20 -> 30]
    
    // Peek front
    int front = queue_peek_front(queue);  // Returns 10
    
    // Dequeue
    int val = queue_dequeue(queue);  // Returns 10, queue now [20 -> 30]
    queue_display(queue);
    
    // Size
    int sz = queue_size(queue);  // Returns 2
    
    // Check empty
    int empty = queue_is_empty(queue);  // Returns 0 (false)
    
    // Clean up
    queue_free(queue);
    return 0;
}
```

## Common Applications
- Task scheduling
- Breadth-first search (BFS)
- Print queue management
- CPU scheduling
