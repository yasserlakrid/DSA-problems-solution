#include<stdio.h>


#include <string.h>
#include <stdlib.h>
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
    while(address != NULL){
        printf("the %d value is : ", i);    
        printf("%d \n" ,address->val);
        i ++ ;
        address= next(address);
    }
   
}


int some(int n){
    if(n == 1){
        return 1 ;
    }else{
        return n + some(n-1); 
    }
}
int quotient(int a  , int b){
    if(a-b < 0){
        return 0 ;
    }else{
        return 1 + quotient(a-b , b); 
    }
}
int reste(int a  , int b){
    if(a-b < 0){
        
        return a;
    }else{
       
      return reste(a-b , b); 
    }
}
int pgcd(int a , int b){
    if (a % b == 0 ){
        return b ;
    }
    if( a % b == 1 ){
        return 1 ;
    }
    return pgcd(b , a % b); 
}
int maxArray(int * A , int  n){
    if(A[n+1] == -1){
        return A[n];
    }else{
        if(A[n] > maxArray(A , n +1 )){
            return A[n];
        }else{
            return maxArray(A , n+1);
        }
    }
}
int fibonati(int n){
 if(n==0 ||  n == 1){
    return 1 ;
 }else{
    return fibonati(n-1) + fibonati(n-2) ; 
 }
}
int product(int a  , int b ){
    if(b== 0){
        return 0 ;
    } 
    if(b == 1){
        return  a;
    }else{
        return a + product(a,b-1) ; 
    }
}
cell * inverse(cell * head){
    cell * H = NULL ;
    if(head == NULL){
        return NULL;
    }
    if(head->addr == NULL){
        return head ;
    }else{
        H = inverse(head->addr);
        head->addr->addr = head;
        head->addr = NULL ;
        return H ;
    }
}
int main(){
    int  a ; 
    cell  head ; 
    scanf("%d" , &a);
    head = buildLinkedList(a);
    displayLinkedlist(head.addr);
    head.addr = inverse(&head);
    displayLinkedlist(head.addr);
    

    printf("the fibonati  %d" , product(4,2));
    return 1; 
}