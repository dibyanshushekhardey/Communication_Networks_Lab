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
int mindist(int distArr[], bool vertArr[]){
    int min = MAX;
    int index;
    for(int i = 0; i < R; i++){
        if(distArr[i] <= min && vertArr[i] == false){
            min = distArr[i];
            index = i;
        }
    }
    return index;
}

void dikstra(int mat[R][R], int src){
    int distArr[R];
    bool vertArr[R];
    int min;

    for(int i = 0;i < R; i++){
        distArr[i] = MAX;
        vertArr[i] = false;
    }

    distArr[src] = 0;
    for(int i = 0; i < R; i++){
        min = mindist(distArr, vertArr);
        vertArr[min] = true;
        for(int j = 0; j < R; j++){
            if(!vertArr[j] && mat[min][j] && distArr[min] + mat[min][j] < distArr[j] && distArr[min] != MAX){
                distArr[j] = distArr[min] + mat[min][j];
            }

        }
    }

    for(int i = 0; i < R; i++){
        printf("%d --- > %d \n", i, distArr[i]);
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
    int src = 0;
    dikstra(mat, src);
    return 0;
}