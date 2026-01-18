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

void primMST(int mat[R][R]) {
    int visited[R] = {0};
    int edgeCount = 0;
    int minCost = 0;

    visited[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edgeCount < R - 1) {
        int min = 9999;
        int u = -1, v = -1;

        for (int i = 0; i < R; i++) {
            if (visited[i]) {
                for (int j = 0; j < R; j++) {
                    if (!visited[j] && mat[i][j] != 0 && mat[i][j] < min) {
                        //printf("Vertices for loop: %d\n", j);
                        min = mat[i][j];
                        //printf("Min Cost: %d\n", min);
                        u = i;
                        v = j;
                        
                    }
                }
            }
        }

        visited[v] = 1;
        edgeCount++;
        minCost += min;

        printf("%d - %d : %d\n", u, v, min);
    }

    printf("\nTotal cost of MST = %d\n", minCost);
}


int main(){
    
    int mat[R][R] = {0};
    
    for (int i = 0; i < R; i++){
        for(int j = 0; j < R; j++){
            addEdge(mat, i, j);     
        }
    }

    displayMatrix(mat); 
    printf("The above is the random adjacency matrix");

    primMST(mat);

    return 0;
} 