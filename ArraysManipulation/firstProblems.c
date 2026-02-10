#include <stdio.h>
#include <stdlib.h>
// minimum of an array
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
// display the elements of an array
void writeArray(int *p , int n ){
    printf("[");
for(int i = 0 ; i < n ; i++ ){
printf(" , %d" , *(p + i));
    }
    printf("] \n");
}
// build a one dimension array
void readArray(int *p , int n){
printf("give the size of the array");
    scanf("%d" , &n);
      for(int i = 0 ; i< n ; i ++ ){
        scanf("%d" , &p[i]);
    }
    
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
int main (void){
    int n = 3 ;
    int p = 0 ;
    printf("%d" , power(n,p));
    printf("the value of polynomial is : %d" , poly());
    getchar();
    getchar();
    return 0 ;
}