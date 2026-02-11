#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// minimum of an arra

int minArray(int *p , int n ){
int min = *p ;
    for( int i = 1 ; i < n ; i ++){
        if(p[i] < min){
            min = p[i]; 
        }
    }
    return min;
}
// maximum of an array
int maxArray(int *p , int n ){
int min = *p ;
    for( int i = 1 ; i < n ; i ++){
        if(p[i] > min){
            min = p[i]; 
        }
    }
    return min;
}

// calculate the students average
int Average(){
    int n ;
    struct student  {
        char name[50] ;
        int grade ;
  
    };
    struct student *students = malloc(sizeof(struct student) * n );

    printf("give the stundents number : ");
    scanf("%d" , &n) ;

    for ( int i = 0 ; i < n ; i ++ ){
        printf("give the %d  student name " , i);
        scanf("%s" , &students[i].name);
        printf("give the %d student grade " , i );
        scanf("%d" , &students[i].grade);
    }
    
    int mean = 0; 
    for (int i = 0 ; i < n ; i ++ ){
        mean += students[i].grade;
    }
    mean = (double) mean / n ;
    free(students);
    return mean ;
}
// gives the p power of n 
int power(int n , int p ){
    
    int pow = 1 ;
for (int i = 0 ; i < p ; i ++ ){
    pow = pow * n ;
}
if (p == 0){
    return 1 ;
 }else {
return pow ;
}

}
// return the value of polynomial based on the values of it coefficients
int poly(){
int deg ;
int *coef;
int sum = 0 ;
int x ;
printf("give the degree : ");
scanf("%d" , &deg);

coef = malloc(sizeof(int) * deg);

for(int i = 0 ; i <= deg ; i ++){
    printf("give the %d coeficient : \n", i );
    scanf("%d" , &coef[i] );
}
printf("give the variable X : \n") ;
scanf("%d" , &x);

for (int i = 0 ; i <= deg; i++){
   sum += coef[i] * power(x,i);
}
free(coef);
return sum ;
}




// display the elements of an array
void writeArray(int *p , int n ){
    printf("[");
for(int i = 0 ; i < n ; i++ ){
printf(" , %d" , *(p + i));
    }
    printf("] \n");
}
// build a one dimension array
void readArray(int *p , int *n){
printf("give the size of the array");
    scanf("%d" , n);
      for(int i = 0 ; i< *n ; i ++ ){
        scanf("%d" , &p[i]);
    }
}
// retunr an array of squares elements 
void buildsequareArray(int *p1 , int *p2 , int *p3, int tai1 , int tai2  , int *n3 )
{
     int j = 0 ;
   int root = 0 ;
    for (int i = 0 ; i < tai1 ; i ++){
         root = (int)sqrt(p1[i]);

if (root * root == p1[i]){
        
            p3[j] = p1[i] ;
            j ++ ;
    }
}
for (int i = 0 ; i < tai1 ; i ++){
         root = (int)sqrt(p2[i]);

        if (root * root == p2[i]){
                    p3[j] = p2[i] ;
                    j ++ ;
            }
}
*n3 = j ;
}
// inteersection of two arrays
void intersaction(int *p1 , int *p2 , int *p3 , int n1 , int n2 , int *n3){
    int k = 0 ;
    bool found ;
for (int i = 0 ; i < n1 ; i++){
    
    for(int j = 0 ; j < n2 ; j++){
        if((p1[i] == p2[j] ) &&( !found )){
            p3[k] = p1[i] ;
            
            k++ ;
        }
    }
}
*n3 = k ;
}
int main (void){
    int *p1 , *p2 , *p3 , n1 ,n2 ,n3 ;

    readArray(p1 , &n1 ) ;
writeArray(p1,n1) ;
readArray(p2 , &n2 ) ;
writeArray(p2,n2);
intersaction(p1,p2,p3,n1,n2,&n3);
writeArray(p3,n3);
    
    getchar();
    getchar();
    return 0 ;
}