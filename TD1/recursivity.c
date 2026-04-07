#include<stdio.h>

#include "stack.h"
#include <string.h>
#include <stdlib.h>
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
int main(){
    int a , b ; 
    printf("give the value of a");
    scanf(" %d" , &a);
    printf("give the value of b ;");
    scanf(" %d" , &b);
    printf("the pgcd %d" , pgcd(a,b));
    return 1; 
}