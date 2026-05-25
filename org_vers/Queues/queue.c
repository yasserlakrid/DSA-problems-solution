#include "queue.h"

/* Create a new queue */
Queue* queue_create(void) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

/* Free queue memory */
void queue_free(Queue *queue) {
    if (!queue) return;
    
    while (queue->front) {
        QueueNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

/* Enqueue element to rear */
void queue_enqueue(Queue *queue, int data) {
    if (!queue) return;
    
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    
    new_node->data = data;
    new_node->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

/* Dequeue element from front */
int queue_dequeue(Queue *queue) {
    if (!queue || !queue->front) {
        printf("Queue is empty\n");
        return -1;
    }
    
    QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->size--;
    
    return data;
}

/* Peek at front element */
int queue_peek_front(Queue *queue) {
    if (!queue || !queue->front) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

/* Peek at rear element */
int queue_peek_rear(Queue *queue) {
    if (!queue || !queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->rear->data;
}

/* Check if queue is empty */
int queue_is_empty(Queue *queue) {
    return queue && queue->front == NULL;
}

/* Get queue size */
int queue_size(Queue *queue) {
    return queue ? queue->size : 0;
}

/* Clear the queue */
void queue_clear(Queue *queue) {
    if (!queue) return;
    
    while (queue->front) {
        QueueNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    queue->rear = NULL;
    queue->size = 0;
}

/* Display queue from front to rear */
void queue_display(Queue *queue) {
    if (!queue) {
        printf("Queue is NULL\n");
        return;
    }
    
    if (queue->front == NULL) {
        printf("Queue is empty []\n");
        return;
    }
    
    printf("Queue (front -> rear): [");
    QueueNode *current = queue->front;
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" -> ");
        current = current->next;
    }
    printf("]\n");
}
