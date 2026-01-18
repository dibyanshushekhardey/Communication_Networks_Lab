#include<stdio.h>
#include <stdlib.h>

#define R 5
# define upper 11
# define lower 1


void addEdge(int mat[R][R], int i, int j){
    int a = rand() % (upper - lower + 1) + lower;
    if(i == j){
        mat[i][j] = 0;
        mat[j][i] = 0;
    }
    else{
        mat[i][j] = a;
        mat[j][i] = a;
    }
    
}
void displayMatrix(int mat[R][R]){
    // looping through the matrix to display it
    for (int i = 0; i < R; i++)
    { // loops through row
        for (int j = 0; j < R; j++){ 
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    int mat[R][R] = {0};
    int D = 0;
    while (D < 11){
        for (int i = 0; i < R; i++){
            for(int j = 0; j < R; j++){
                addEdge(mat, i, j);
                D++;
            }
    }

    }
            

    displayMatrix(mat); 
    printf("The above is the random adjacency matrix");
    return 0;
} 