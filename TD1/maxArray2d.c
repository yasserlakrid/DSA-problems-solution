#include <stdlib.h>
#include <stdio.h>
#define MaxRow 20
#define MaxCol 20


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
int maxMat(int ** mat,int row,int col) {
    int max = mat[0][0];
    int maxRow = 0;
    for (int i = 0;i < row; i++ ) {
        for (int j = 0;j < col; j++ ) {
            if(max < mat[i][j]) {
                maxRow = i;
                max = mat[i][j];
            };
        }
    }
    return maxRow;
}
int main (){
    buildMat(&mat,&row,&col);
    writeMat(mat, &row,&col);
    printf("the biggest element is in the row : %d ",maxMat(mat, row,col));
    return 1;
}