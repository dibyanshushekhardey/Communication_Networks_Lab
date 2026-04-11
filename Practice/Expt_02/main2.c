#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define R 10
#define upper 10
#define lower 1
#define MAX 999

void addEdge(int mat[R][R], int i, int j){
    int a = rand() % (upper - lower + 1) + lower;
    mat[i][j] = a;
    mat[j][i] = a;
}

void displayMat(int mat[R][R]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int minDist(int distArr[], bool verArr[]){
    int minm = MAX;
    int index;
    for(int i = 0; i < R; i++){
        if(distArr[i] <= minm && verArr[i] == false){
            minm = distArr[i];
            index = i;
        }
    }
    return index;
}

void dikstra(int mat[R][R], int src){
    int distArr[R];
    bool verArr[R];
    int minm;

    for(int i = 0; i < R; i++){
        distArr[i] = MAX;
        verArr[i] = false;
    }
    distArr[src] = 0;
    for(int i = 0; i < R; i++){
        minm = minDist(distArr, verArr);
        verArr[minm] = true;
        for(int j = 0; j < R; j++){
            if(!verArr[j] && mat[minm][j] && distArr[minm] + mat[minm][j] < distArr[j] && distArr[minm] != MAX){
                distArr[j] = distArr[minm] + mat[minm][j];
            }
        }

    }
    for(int i = 0; i < R; i++){
        printf("%d -----> %d\n", i, distArr[i]);
    }

}

int main(){
    int mat[R][R] = {0};
    for(int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            addEdge(mat, i, j);
        }
    }

    displayMat(mat);
    dikstra(mat, 0);
    return 0;
}