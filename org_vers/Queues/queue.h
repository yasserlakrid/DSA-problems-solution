#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/* Queue node structure */
typedef struct queue_node {
    int data;
    struct queue_node *next;
} QueueNode;

/* Queue structure */
typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

/* ===== Initialization and Memory Management ===== */
Queue* queue_create(void);
void queue_free(Queue *queue);

/* ===== Core Operations ===== */
void queue_enqueue(Queue *queue, int data);
int queue_dequeue(Queue *queue);
int queue_peek_front(Queue *queue);
int queue_peek_rear(Queue *queue);

/* ===== Utilities ===== */
int queue_is_empty(Queue *queue);
int queue_size(Queue *queue);
void queue_clear(Queue *queue);

/* ===== Display ===== */
void queue_display(Queue *queue);

#endif
