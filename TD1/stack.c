#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(cell * *stack_t , cell * node ){
    
    if(*stack_t){
        node->next = *stack_t ; 

        *stack_t  = node ; 
        
    }else{
        
        *stack_t  = node ; 
    }
}

void diplayStack(cell * stack_t ){
    
    while(stack_t){
        printf("%c |" , stack_t->val);
        stack_t = stack_t->next ; 
    }
    printf("\n");
}
int pop(cell * *top){
    int save  ;
    cell * savePointer  = NULL; 
     if(*top == NULL){
        printf("the stack is empty \n");

        return -1 ;
    }else{
         save = (*top)->val ;
        savePointer = *top ; 
         if((*top)->next){
        
        *top = (*top)->next ;
        free(savePointer);
    }else if (*top != NULL){
        *top = NULL;
        free(savePointer);
    }
    }
    
    
   
    return save ; 
}
