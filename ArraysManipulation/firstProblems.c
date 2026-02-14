#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/**
 
// Minimum of an array
int minArray(int *p, int n) {
    int min = *p;
    for (int i = 1; i < n; i++) {
        if (p[i] < min) {
            min = p[i];
        }
    }
    return min;
}

// Maximum of an array
int maxArray(int *p, int n) {
    int max = *p;  // fixed: was using 'min' instead of 'max'
    for (int i = 1; i < n; i++) {
        if (p[i] > max) {
            max = p[i];
        }
    }
    return max;
}

// Calculate the students' average
double Average() {
    int n;
    struct student {
        char name[50];
        int grade;
    };

    // Ask for number of students BEFORE malloc
    printf("Give the students number: ");
    scanf("%d", &n);

    struct student *students = malloc(sizeof(struct student) * n);
    if (!students) { // Check malloc success
        printf("Memory allocation failed!\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Give the %d student name: ", i + 1);
        scanf("%s", students[i].name); // no &
        printf("Give the %d student grade: ", i + 1);
        scanf("%d", &students[i].grade);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
    }

    double mean = (double)sum / n;
    free(students); // Free memory
    return mean;
}

// Calculates n to the power of p
int power(int n, int p) {
    int pow = 1;
    for (int i = 0; i < p; i++) {
        pow *= n;
    }
    return pow; // simplified: p==0 case handled by loop naturally
}

// Return value of polynomial given coefficients
int poly() {
    int deg;
    int *coef;
    int sum = 0;
    int x;

    printf("Give the degree: ");
    scanf("%d", &deg);

    coef = malloc(sizeof(int) * (deg + 1)); // fix: allocate deg+1
    if (!coef) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    for (int i = 0; i <= deg; i++) {
        printf("Give the %d coefficient: ", i);
        scanf("%d", &coef[i]);
    }

    printf("Give the variable X: ");
    scanf("%d", &x);

    for (int i = 0; i <= deg; i++) {
        sum += coef[i] * power(x, i);
    }

    free(coef);
    return sum;
}

// Return an array of perfect square elements
void buildSquareArray(int *p1, int *p2, int *p3, int size1, int size2, int *size3) {
    int j = 0;
    int root = 0;
    for (int i = 0; i < size1; i++) {
        root = (int)sqrt(p1[i]);
        if (root * root == p1[i]) {
            p3[j++] = p1[i];
        }
    }

    for (int i = 0; i < size2; i++) {
        root = (int)sqrt(p2[i]);
        if (root * root == p2[i]) {
            p3[j++] = p2[i];
        }
    }

    *size3 = j;
}

// Intersection of two arrays
void intersection(int *p1, int *p2, int *p3, int n1, int n2, int *n3) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        bool found = false; // fix: initialize inside outer loop
        for (int j = 0; j < n2; j++) {
            if (p1[i] == p2[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            p3[k++] = p1[i];
        }
    }
    *n3 = k;
}

// Union of two arrays
void unionOfArrays(int *p1, int *p2, int *p3, int n1, int n2, int *n3) {
    int k = 0;
    // Copy all elements of p1
    for (int i = 0; i < n1; i++) {
        p3[k++] = p1[i];
    }

    // Add elements of p2 that are not already in p3
    for (int i = 0; i < n2; i++) {
        bool found = false;
        for (int j = 0; j < n1; j++) {
            if (p2[i] == p1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            p3[k++] = p2[i];
        }
    }

    *n3 = k;
}


// Physical deletion of elements
void physicalDeletion(int *p1, int *n1, int pos, int el) {
    for (int i = pos; i < *n1 - el; i++) {
        p1[i] = p1[i + el];
    }
    *n1 -= el; // fix: update array size after deletion
}
// read an array 

 */
int* Array(int *n){
    printf("give the length of your array sir : ");
    scanf("%d" , n);
    int *p = malloc(sizeof(int) * (*n));
    for(int i = 0 ; i< *n ; i++){
        printf("give the %d element of your array : " , i); 
        scanf("%d" , &p[i]);
    }
    return p ;
}
void writeArray(int *p , int n){
    printf("[");
    for(int i=0 ; i < n ; i++ ){
        if(i){
            printf(" , %d ",p[i]);
        }
        else{
            printf("%d" , p[i]);
        }
    }
    printf("]");
}
//insert a value based on an index 
void insert(int *p , int *size  , int position , int inserted){
    p = realloc(p , sizeof(int) * (*size + 1) );
    
    for(int i = *size ; i > position  ; i--){

        p[i] = p[i - 1];

    }
   
    *size = *size + 1 ;
    p[position ] = inserted;
}
int main(void) {
    int *p ;
    int n , i , po;
    p = Array(&n); 
    writeArray(p,n);
    printf("what value do you want to insert : ");
    scanf("%d" , &i);
    printf("at which position ? ");
    scanf("%d", &po);
    insert(p,&n,po, i );
    writeArray(p,n);
    free(p);
    printf("\n");
    return 0;
}
