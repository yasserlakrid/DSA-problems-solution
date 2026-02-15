#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


void allocate(cell* *p){
    *p = malloc(sizeof(cell));
};

void assignVal (cell *p , int val){
    p->val = val ;
};

int value( cell *p ){
    return p->val;
};

void assignaddr(cell *p , cell * add){
    p->addr = add ;
};

cell * next(cell *p){
    return p->addr ;
};

