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
    printf("give the position you want to insert your element in : ");
    scanf("%d" , &pos);

    if(insertElementDoublyList( &list , pos )){
        displayLinkedList(list);
    }else{
        printf("fuck you !\n");
    }
    
    return 1;
}