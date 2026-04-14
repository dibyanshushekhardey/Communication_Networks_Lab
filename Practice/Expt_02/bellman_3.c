#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define R 10 
#define MAX 999

void dispMat(int mat[R][R]){
    for(int i = 0; i < R; i++){
        for (int j = 0; j < R; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
        
    }
}

void addEdge(int mat[R][R], int i, int j, int w){
    mat[i][j] = w;
}

void belmanFord(int mat[R][R], int src){
    int distArr[R] = {0};

    for(int i = 0; i < R; i++){
        distArr[i] = MAX;
    }

    distArr[src] = 0;

    for(int k = 0; k < R-1; k++){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < R; j++){
                if(distArr[i] != MAX && mat[i][j] != 0 && distArr[i] + mat[i][j] < distArr[j]){
                    distArr[j] = distArr[i] + mat[i][j];
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            if(distArr[i] != MAX && mat[i][j] != 0 && distArr[i] + mat[i][j] < distArr[j]){
                printf("\nNegative Cycle detected!\n");
            }
        }
    }

    for(int i = 0; i < R; i++){
        printf("%d --> %d\n", i, distArr[i]);
    }
}
int main(){
    int mat[R][R] = {0};
    addEdge(mat , 0, 1, 1);
    addEdge(mat , 0, 9, 3);
    addEdge(mat , 1, 2, 5);
    addEdge(mat , 1, 7, 2);
    addEdge(mat , 2, 1, 4);
    addEdge(mat , 2, 3, -6);
    addEdge(mat , 2, 4, 2);
    addEdge(mat , 3, 8, -3);
    addEdge(mat , 4, 3, 7);
    addEdge(mat , 4, 5, -10);
    addEdge(mat , 5, 6, 7);
    addEdge(mat , 6, 7, 4);
    addEdge(mat , 7, 5, -5);
    addEdge(mat , 7, 8, 2);
    addEdge(mat , 8, 6, 9);
    addEdge(mat , 8, 0, 8);
    addEdge(mat , 9, 8, -4 );
    dispMat(mat);
    belmanFord(mat, 0);
    dispMat(mat);
    return 0;

}