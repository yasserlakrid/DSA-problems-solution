#include <stdlib.h>
#include <stdio.h>
#include "queues.h"

void enqueue(queue *queue , int val){
    cell *element ;
    element = malloc(sizeof(cell));
    element->val = val ;
    element->next = NULL ;
    if(!(*queue).head){
        printf("the queue is empty ");
        (*queue).tail = element;
        (*queue).head = element ;

    }else{
        (*queue).tail->next = malloc(sizeof(cell));
        (*queue).tail->next = element;
        (*queue).tail = (*queue).tail->next;
    }

}
void displayQueue(queue queue ){
    cell * head = queue.head;
    if(!queue.head){
        printf("the queue is empty");
        return;
    }
    while (head->next)
    {
        printf("the value is : %d \n", head->val);
        head = head->next ;
    }
    printf("the value is : %d \n",head->val);
}
void dequeue(queue *queue){
    if(queue->head && queue->head->next){
        (*queue).head = (*queue).head->next;
        
    }
    else if(queue->head && !queue->head->next){
        (*queue).head = NULL;
    }else{
        return;
    }
    
}
