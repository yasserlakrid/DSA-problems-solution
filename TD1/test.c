#include<stdio.h>

#include "stack.h"
#include <string.h>
#include <stdlib.h>
cell * top = NULL ; 
int openingBrackets(char c){
    return (c=='['|| c=='{' || c=='(');
}
char reverse(char c){
    if(c=='{'){
        return '}';
    }
    if(c=='('){
        return ')';
    }
    if(c=='['){
        return ']';
    }


}
int matchingClose(char c , cell * stackTop){
   
    return ((c==reverse(stackTop->val))&&  (!openingBrackets(c))) ;
    
}
int correctExpression(char expression[]){
    cell *character;

    for(int i = 0 ; i < strlen(expression) ; i++){
    
       if(openingBrackets(expression[i])){
        character = malloc(sizeof(cell));
        character->val = expression[i] ;
        push(&top , character); 

       
    }

       if((matchingClose(expression[i] , top))){

        pop(&top);
        
    }
    }
   
    if(top == NULL ){
        return 1 ;
    }
    return 0 ;
}
int main(){
  
    cell *element ; 
    if(correctExpression("({a+b)}")){
        printf("the expression is correct ");
    }else{ 
        printf("the expression is incorrect ");

    }
    
  
    return 1;
}
