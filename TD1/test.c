#include<stdio.h>
#include "doublyLists.h"
#include <stdlib.h>
#include "linkedList.h"
int main(){
    dlist list ;
    int n ;
    printf("give the length of your doubly list : " );
    scanf("%d",&n);
    list = buildDoublyLinkedList(n);
    traverseDoubly(list);
    return 1;
}