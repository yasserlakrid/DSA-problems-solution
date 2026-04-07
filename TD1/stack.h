#ifndef stacks
#define stacks

typedef struct cell{
    char val ;
    struct cell * next ;
}cell ;
typedef cell * stack ; 
void push(cell * * stack_t , cell * node );
void diplayStack(cell *stack_t );
int pop(cell * *top);
#endif