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

void displayLinkedlist(cell * head){
    cell * address = head;
    int i = 1 ;
    while(address){
        printf("the %d value is : ", i);    
        printf("%d \n" ,address->val);
        i ++ ;
        address= next(address);
    }
   
}

cell * mostOccurrences(cell * head ){
   int count = 0 ;
   cell * head2 = head;
   int maxCount =  0 ;
   cell * base = head ;
   cell * maxElement = head; 
   while(head){
    count = 0 ;
    while(head2){
       
        if(head->val == head2->val){
            count ++ ;
        }
        head2 = next(head2);
    }
    if(count > maxCount){
        maxElement = head;
        maxCount = count;
    }
    head = next(head);
    head2 = base ;
   }
    return maxElement;
}

cell * accessByValue (cell * head , int value ){
while(head){
    if(head->val == value){
        return head ;
    }
    head = next(head) ;
}
}
cell * accessByPosition(cell * head , int position){
    int i = 1 ; 
    while(i<position && head){
        i++ ;
        head = next(head);
    }
    return head;
}

int listLength(cell * head){
    int i = 0;
    while(head){
        i++;
        head = next(head);
    }
    return i;
}
void deleteByValue(cell * *head , int value){
    cell * save = *head;
    cell * pre = *head;
    if((*head)->val==value){
       * head  = next(*head);
    }

    while(save && save->val != value){
        pre = save ;
        save = next(save);
    }
    assignaddr(pre , next(save));
}
int main(){
    int n ;
    printf("give the value number of items in the list : ");
    scanf("%d ",&n);
    cell link = buildLinkedList(n);
    displayLinkedlist(link.addr);

    deleteByValue(&link.addr , 5);
    displayLinkedlist(link.addr);
    return 0;
}