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
void deleteByPosition(cell ** head , int position ){
    cell * save = *head ;
    cell * pre = *head;
    if(position == 1){
        *head = next(*head);
    }
    else{
        int i =  1 ;
    while(i < position && save){
        pre = save;
        i++;
       save = next(save);
    }
    assignaddr(pre,next(save));

    }
    
}
void insertByPosition(cell * *head , cell *element , int position){
    int i = 0 ;
    if(position ==1){
        assignaddr(element,*head);
        *head = element;
        return;
    }
    cell * pre = *head;
    while(i < position  && pre){
        pre = next(pre);
        i ++ ;
    }   
    assignaddr(element ,next(pre));
   assignaddr(pre,element);
   

}
cell *mergeLinkedlists(cell *head1, cell *head2)
{
    cell *i = head1;
    cell *j = head2;
    cell *savI = i;
    cell *savJ = j;

    while (i && j)
    {
        if (j->val >= i->val)
        {
            while ( i && j && j->val >= i->val)
            {
                savI = i;
                i = next(i);
            }
            assignaddr(savI, j);
           
        }
        else
        {
            while ( i && j && j->val <= i->val)
            {
                savJ = j;
                j = next(j);
            }
            assignaddr(savJ, i);
            

        }

    }
   if(i){
    assignaddr(savJ,i);
   }else if (j){
    assignaddr(savI,j);
   }
   
    if (head1->val > head2->val)
    {
        return head2;
    }
    else
    {
        return head1;
    }
}
void splitLinkedList(cell * head , cell * head1 , cell *head2 ){
    while(head){
        if(head->val % 2 == 0){
            head1->addr = head;
            head1 = head ;
        }else{
            head2->addr = head;
            head2 = head ;
        }
        
        head = next(head);
    }
    head1->addr = 0;
        head2->addr = 0;
}
void bubbleSort(cell * head){
    int unordered = 1 ;
    int save ;
    cell * index = head;
    if(!head || !head->addr){
        return;
    }else{
        while(unordered){
        unordered = 0 ;
        index = head;
        while(index->addr){
            
            if(index->val > next(index)->val){
                save = index->val;
                index->val = next(index)->val;
                next(index)->val = save;
                unordered = 1;
            }
            index = next(index);
        }
        
    }
    } 
    
}

int *buildArray(int length){
    int * array;
    array = malloc(sizeof(int)*length);

    for(int i = 0 ; i < length ; i ++){
        scanf("%d",&array[i]);
    }
    
    return array;
}
#include <stdlib.h>

int* merge(int* array1, int length1, int* array2, int length2) {
    int i = 0;
    int j = 0;
    int k = 0;

    // Allocate memory for the merged array
    int* array3 = (int*)malloc((length1 + length2) * sizeof(int));
    if (array3 == NULL) {
        return NULL; // allocation failed
    }

    // Merge while both arrays still have elements
    while (i < length1 && j < length2) {
        if (array1[i] < array2[j]) {
            array3[k++] = array1[i++];
        } else {
            array3[k++] = array2[j++];
        }
    }

    // Copy remaining elements from array1
    while (i < length1) {
        array3[k++] = array1[i++];
    }

    // Copy remaining elements from array2
    while (j < length2) {
        array3[k++] = array2[j++];
    }

    return array3;
}

int *mergeSort( int * array , int  length){
    int *array1 , *array2;
    int *merged;
    if(length < 2){
        return array;
    }else{
        int mid = length / 2 ;
        array1 = malloc(sizeof(int) * mid);
        array2 = malloc(sizeof(int )* (length - mid ));
        for(int i = 0 ; i < mid ; i ++){
            array1[i] = array[i];
            
        }
        for(int i = mid ; i < length ; i++){
            array2[i - mid] = array[i];
        }
        array1 = mergeSort(array1 , mid);
        array2 = mergeSort(array2,length - mid );
         merged = merge(array1,mid,array2,(length - mid));
         return merged;
    }
    
}


int power(int x , int p){
    int sav = x ;
    if(p == 0 ){
        return 1 ;
    }
    for(int i = 1 ; i < p ; i++ ){
        x = sav * x;
    }
    return x ;
}
int calculatePolynomialValue(cell * pol , int x){
    int res = 0 ;
    int i = 0 ;
    int coef ;
    int current ;
    while(pol){
        coef = pol->val ;
        
        
        current = coef * power(x,i);
        res =res +  current;
      
        pol = next(pol);
        i++;
    }
    return res;
}
void displayPolynomial(cell * p ){
 int i = 1 ;
 printf("%d ", p->val);

 p = p->addr;
 while (p->addr)
 {
    printf(  " + %d X ^ %d  " , p->val , i);
    i++ ;
    p = next(p);
 }
 printf("\n");
}
void derivate(cell ** pol){
    int i = 0 ;
    cell * sav = * pol ;
    while(sav){
        sav->val = sav->val * i;
        sav = next(sav);
        i ++ ;
    }
    *pol = (*pol)->addr;

}
cell * buildPolynomial(int deg){
    int i = 0 ; 
    cell * head;
    cell * p;
    head = malloc(sizeof(cell));
    p = head;
    while(i <= deg){
        printf("give the %d coefficient : " , i);
        scanf("%d" , &(p->val));
        i++;
        p->addr = malloc(sizeof(cell));
        p = next(p);
    }
    return head;
}

cell * polynomialSum(cell * pol1 , cell *pol2){
    cell * head ;
    head = malloc(sizeof(cell));
    cell * sav = head;
    while(pol1->addr || pol2->addr){     
        int v1  = (pol1->val) ? pol1->val : 0;
        int v2  = (pol2->val) ? pol2->val : 0;
        sav->val = v1+ v2;

        if(pol1->addr){
            pol1 = pol1->addr;
        }
        if(pol2->addr){
            pol2 = pol2->addr;
        }

        sav->addr = malloc(sizeof(cell));
        sav = next(sav);

    }
    
    sav->addr = NULL;
    return head;
}

int main(){
    cell* pol ;
    cell *pol2 ;
    cell *sum;
    int degree , degree2;
    int X;
    printf("give the degree of your polynomial : ");
    scanf("%d",&degree);
    pol = buildPolynomial(degree);
    displayPolynomial(pol);
    printf("give the degree of the second polynomial : ");
    scanf("%d",&degree2);
    pol2 = buildPolynomial(degree2);
    displayPolynomial(pol2);
    sum = polynomialSum(pol,pol2);
    displayPolynomial(sum);

    
    return 0;
}