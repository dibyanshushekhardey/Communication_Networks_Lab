#include <stdio.h>
#include <stdbool.h>

#define V 10
#define MAX 999

int minDist(int distArr[], bool vertArr[]){
    int minm = MAX;
    int index;
    for (int i = 0; i < V; i++){
        if(distArr[i] <= minm && vertArr[i] == false){
            minm = distArr[i];
            index = i;
        }
    }
    return  index;
}
void Dijkstra(int mat[V][V], int src){
    int distArr[V];
    bool vertArr[V];
    int min;
    for(int i = 0; i < V; i++){
        distArr[i] = MAX;
        vertArr[i] = false;
    }

    distArr[src] = 0;
    for(int i = 0;  i < V; i++){
        min = minDist(distArr, vertArr);
        vertArr[min] = true;
        for(int j = 0; j < V; j++){
            if(!vertArr[j] && mat[min][j] && distArr[min] != MAX && distArr[min] + mat[min][j] < distArr[j]){
                distArr[j] = distArr[min] + mat[min][j];
            }
        }
    }
    printf("Dijkstra shortest paths are:\n");
    for(int i = 0; i < V; i++){
        printf("%d ---> %d\n", i, distArr[i]);
    }

}

void addEdge(int mat[V][V], int i, int j, int w){
	mat[i][j] = w;
	mat[j][i] = w;
}


// to display matrix
void displayMatrix(int mat[V][V]){
	for (int i = 0; i < V; i++)
	{
		/* code */
		for (int j = 0; j < V; j++)
		{
			/* code */
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
    /* code */
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
    
    Dijkstra(mat, 0);
    return 0;
}