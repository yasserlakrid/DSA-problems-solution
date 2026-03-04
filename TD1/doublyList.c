#include<stdio.h>
#include "doublyLists.h"
#include <stdlib.h>

dlist buildDoublyLinkedList(int length){

  
  
   dcell * save;
   dcell * current;

   dlist list ;
   list.head = malloc(sizeof(dcell));

   
 

    
    current = list.head;

    list.head->prev = NULL;

   for(int o = 0 ; o < length ; o ++){

    save = current;
    current->next = malloc(sizeof(dcell));
    current = current->next;
    current->prev = save ;
    printf("give the %d value" , o );
    scanf("%d" , &current->val);
    
   }
   list.tail = current ;
   list.tail->next = NULL;
   return list;
}

void displayLinkedList(dlist  list ){
 dcell * head = list.head->next;

 int i =0 ;
 while (head)
 {
    printf("the %d value is : %d \n",i,head->val);
    i++;
    head = head->next;
 }
 
}
void traverseDoubly(dlist list){
    dcell * head = list.head->next;
    dcell * tail = list.tail->prev;
    printf("going forward : \n");
    int i = 0 ;
    while (head)
    {
        printf("the %d value is : %d \n" , i,head->val);
        head = head->next;
        i ++ ;
    }
    printf("going backward \n");
    while (tail)
    {
        printf("the %d value is : %d \n" , i , tail->val);
        tail = tail->prev;
        i--;
    }
    
    
}
int insertElementDoublyList( dlist *list , int pos ){
    dcell *element ;
    dcell *next ;
    element = malloc(sizeof(dcell));

    
    dcell * head = list->head->next ; 
    int i = 0 ;
    while( head->next && i < pos){
        head = head->next;
        i ++ ;
    }
    if(i < pos){
        printf("the position doesn't exist \n");
        return 0 ;
    }else{
    printf("give the element value :");

    scanf("%d",&element->val);

    head = head->prev ;

    if(head->next && head->prev){
    next = head->next;
    head->next = element;
    next->prev = element;
    element->next = next ;
    element->prev = head;
    }else if((!head->next) && (i == pos)){
        
        head->next = element ;
        element->prev = head;
        element->next = NULL;
    }else if (!head->prev && head->next){
        head->prev = element ;
        element->next = head ;
        list->head = element ;
    }
    }
    
    
    return 1 ;

   
}
