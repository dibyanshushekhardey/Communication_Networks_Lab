#include <stdio.h>
#include <stdbool.h>

#define V 10
#define MAX 999

void BellmanFord(int mat[V][V], int src){
    int distArr[V];

    // Initialize distances
    for(int i = 0; i < V; i++){
        distArr[i] = MAX;
    }
    distArr[src] = 0;

    // Relaxing all edges V-1 times
    for(int k = 0; k < V - 1; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(mat[i][j] != 0 && distArr[i] != MAX &&
                   distArr[i] + mat[i][j] < distArr[j]){
                    distArr[j] = distArr[i] + mat[i][j];
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(mat[i][j] != 0 && distArr[i] != MAX &&
               distArr[i] + mat[i][j] < distArr[j]){
                printf("Graph contains a negative weight cycle\n");
                return;
            }
        }
    }

    // Print result
    printf("Bellman-Ford shortest paths are:\n");
    for(int i = 0; i < V; i++){
        printf("%d ---> %d\n", i, distArr[i]);
    }
}

void addEdge(int mat[V][V], int i, int j, int w){
    mat[i][j] = w;
    // For undirected graph, keep this:
    //mat[j][i] = w;
}

// Display matrix
void displayMatrix(int mat[V][V]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int mat[V][V] = {0};

    addEdge(mat, 0, 1, 1);
    addEdge(mat, 0, 9, 3);
    addEdge(mat, 1, 2, 5);
    addEdge(mat, 1, 7, 2);
    addEdge(mat, 2, 1, 4);
    addEdge(mat, 2, 3, -6);
    addEdge(mat, 2, 4, 2);
    addEdge(mat, 3, 8, -3);
    addEdge(mat, 4, 3, 7);
    addEdge(mat, 4, 5, -10);
    addEdge(mat, 5, 6, 7);
    addEdge(mat, 6, 7, 4);
    addEdge(mat, 7, 5, -5);
    addEdge(mat, 7, 8, 2);
    addEdge(mat, 8, 6, 9);
    addEdge(mat, 8, 0, 8);
    addEdge(mat, 9, 8, -4 );
    

    printf("Adjacency Matrix Representation\n");
    displayMatrix(mat);
    
    BellmanFord(mat, 0);
    return 0;
}
