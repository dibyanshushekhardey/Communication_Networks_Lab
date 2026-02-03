
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define V 4
#define MAX 999

void floydWarshall(int mat[V][V]);
int minDist(int distArr[], bool vertArr[]);
void addEdge(int mat[V][V], int i, int j, int w);
void displayMatrix(int mat[V][V]);
int min(int, int);

int min(int i, int j){
	int min = 0;
	if (i < j){
		min = i;
	}
	else{
		min = j;
	}
	return min;
}

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

void floydWarshall(int mat[V][V]){
	for (int i = 0; i < V; i++)
	{
		/* code */
		for (int j = 0; j < V; j++)
		{
			/* code */
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
	printf("The matrix after adding infinity is\n");
	displayMatrix(mat);

	for(int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if (mat[i][j]> mat[i][k] + mat[k][j]){ // (mat [i][k] != MAX && mat[k][j] != MAX)  { // && (mat [k][j] != MAX && mat[i][k] != MAX))
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
					//mat[i][j] = mat[i][k] + mat[k][j];
				}
				else{
					mat[i][j] = mat[i][j];
				}
			}
			
		}
		printf("Step %d\n", k+1);
		printf("----------------\n");
		displayMatrix(mat);
		printf("----------------\n");
	}

	printf("The matrix after adding Alg implementation is\n");
	displayMatrix(mat); 


}
void addEdge(int mat[V][V], int i, int j, int w){
	mat[i][j] = w;
	//mat[j][i] = w;
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
    addEdge(mat, 0, 1, 5);
    addEdge(mat, 0, 2, -5);
    addEdge(mat, 1, 0, 4);
    addEdge(mat, 2, 1, 7);
    addEdge(mat, 3, 2, 6);
    addEdge(mat, 1, 3, -2);
    //addEdge(mat, 0, 1, 1);
    printf("Adjacency Matrix Representation\n");
    displayMatrix(mat);
    floydWarshall(mat);
    
    //Dijkstra(mat, 0);
    return 0;
}
