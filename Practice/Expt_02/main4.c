#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 999
#define R 10

void addEdge(int mat[R][R], int i, int j, int w){
    mat[i][j] = w;
}

void dispMat(int mat[R][R]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int minVal(int i, int j){
    int min = 0;
    if(i < j){
        min = i;
    }
    else{
        min = j;
    }
    return min;
}

int mindist(int distArr[], bool vertArr[]){
    int min = MAX;
    int index;
    for(int i = 0; i < R; i++){
        if(vertArr[i] == false && distArr[i] <= min){
            min = distArr[i];
            index = i;
        }
    }
    return index;
}

void floydWarshall(int mat[R][R]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            if(i == j){
                mat[i][j] = 0;
            }
            else{
                if(i != j && mat[i][j] != 0){
                    mat[i][j] = mat[i][j];
                }
                else{
                    mat[i][j] = MAX;
                }
            }
        }
    }

    for(int k = 0; k < R; k++){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < R; j++){
                if(mat[i][j] > mat[i][k] + mat[k][j]){
                    mat[i][j] = minVal(mat[i][j], mat[i][k] + mat[k][j]);
                }
                else{
                    mat[i][j] = mat[i][j];
                }
            }
        }
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
    printf("-------------------------\n");
    floydWarshall(mat);
    dispMat(mat);
    return 0;
}