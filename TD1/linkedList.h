#ifndef linkedList
#define linkedList
typedef struct cell  {
    int val ;
    struct cell * addr  ;
} cell;

void allocate(cell* *p);

void assignVal (cell *p , int val);

int value( cell *p );

void assignaddr(cell *p , cell * add);

cell * next(cell *p);

#endif
