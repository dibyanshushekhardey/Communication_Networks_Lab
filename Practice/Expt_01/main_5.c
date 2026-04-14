#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define R 10
#define upper 10
#define lower 1

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

void displayMat(int mat[R][R]){
    for(int i = 0; i < R;i++){
        for(int j = 0; j < R; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void primMST(int mat[R][R]){
    int visited[R] = {0};
    int edgeCount = 0;
    int minCost = 0;

    visited[0] = 1;

    while(edgeCount < R-1){
        int min = 999;
        int u = -1, v = -1;
        for(int i = 0; i < R; i++){
            if(visited[i]){
                for(int j = 0; j < R; j++){
                    if(!visited[j] && mat[i][j] != 0 && mat[i][j] < min){
                        min = mat[i][j];
                        u = i;
                        v = j;
                    }
                }
            }    
        }
        visited[v] = 1;
        edgeCount++;
        minCost += min;
    }
    printf("\nTotal MST Cost is %d", minCost);
}
int main(){
    int mat[R][R] = {0};
    for(int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            addEdge(mat, i, j);
        }
    }
    displayMat(mat);
    primMST(mat);

    return 0;

}