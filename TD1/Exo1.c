#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"


cell buildLinkedList (int n){
    cell cell1 ;
    cell *p , *previous; 
    int value ;
    cell head;
    printf("give the value of the first cell : ");
    scanf("%d",&value);
    allocate(&p);
    assignVal(p,value);
    head.addr=p;

    for(int i = 2 ; i <= n ; i++){
        printf("give the value of the %d cell : " , i);
        scanf("%d",&value);
        previous = p ;
        allocate(&p);
        assignVal(p,value);
        assignaddr(previous,p); 
    } 
    return head;

}
int displayLinkedlist(cell * head){
    cell * address = head;
    int i = 1;
    while(address){
        printf("the %d value is : ",i);
        printf("%d \n" ,address->val);
        i ++ ;
        address= next(address);
    }
    return i -1 ;
}

int  main(){
    cell link = buildLinkedList(3); // build a linked list and return the the first cell (address and undefind value)
    int length = displayLinkedlist(link.addr); // display a linked list and return it's length 
    printf("the length of the linked list is : %d \n",length);
    return 1;

}