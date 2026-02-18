#include <stdlib.h>
#include <stdio.h>
#define MaxRow 20
#define MaxCol 20


int ** mat;
int row,col;
void readMat(int** mat ,int *row,int *col) {
    printf("give the number of rows and columns : ");
    scanf("%d %d",row,col);
    mat =(int**)malloc(sizeof(int*)*(*row));
    for (int i = 0;i < *row; i++ ) {
        mat[i] =(int *)malloc(sizeof(int )*(*col));
        for (int j = 0;j < *col; j++ ) {

            printf("give the value of the cell [%d][%d] : ",i + 1,j + 1);
            scanf("%d",&mat[i][j]);
        }  
    }
}

void writeMat(int mat[MaxRow][MaxCol],int *row,int *col) {
    for (int i = 0;i < *row; i++ ) {
        for (int j = 0;j < *col; j++ ) {
            printf("%d _ ",mat[i][j]);
        }
        printf("\n"); 
    }
}

int maxMat(int mat[MaxRow][MaxCol],int row,int col) {
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
    readMat(mat,&row,&col);
    writeMat(mat,&row,&col);
    printf("Max is in the row: %d",maxMat(mat,row,col) + 1);
    return 1;
}