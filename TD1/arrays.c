#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
int ** mat;
int row,col;
void buildMat(int* **mat , int *row , int *col){
    printf("give the number of row : ");
    scanf("%d",row);
    printf("give the number of colomn : ");
    scanf("%d",col);
    *mat = malloc(sizeof(int*) * (*row));
    for(int i = 0 ; i < *row ; i++){
        (*mat)[i] = malloc(sizeof(int) * (*col));
        for(int j=0 ; j < *col ; j++){
            printf("mat [%d][%d] ", (i),(j));
            scanf("%d", &(*mat)[i][j]);
        }
    }
    

}
void writeMat(int **mat , int *row , int *col){
for(int i = 0 ; i < *row ; i++){
    
        for(int j=0 ; j < *col ; j++){
            printf("%d , ", mat[i][j]);
        }

        printf("\n");
    }
}