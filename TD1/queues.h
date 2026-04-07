#ifndef queues
#define queues
typedef struct cell{
    int val ;
    struct cell * next ;
}cell ;

typedef struct queue {
    cell* head ;
    cell* tail;
} queue ;

void enqueue(queue *queue , int val);
void displayQueue(queue queue );
void dequeue(queue *queue);
#endif