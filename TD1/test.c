#include<stdio.h>
#include "doublyLists.h"
#include <stdlib.h>
#include "linkedList.h"
int main(){
    dlist list ;
    int n ;
    int pos ; 

    printf("give the length of your doubly list : " );
    scanf("%d",&n);
    list = buildDoublyLinkedList(n);
    displayLinkedList(list);
    printf("give the element you want to remove : ");
    scanf("%d" , &pos);

    
         deleteElement(list,pos);
         displayLinkedList(list);
   
    
    return 1;
}
