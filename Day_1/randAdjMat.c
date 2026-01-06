#include<stdio.h>
#include <stdlib.h>

#define R 5
# define upper 10
# define lower 0


void defEdge(int mat[R][R], int i, int j){
	// definign matrices and initialising with values 1
	mat[i][j] = 1; // once i have declare a matrix in function parameters, no need to declare it again 
	mat[j][i] = 1; // why?
}

void displayMatrix(int mat[R][R]){
	// looping through the matrix to display it
	for (int i = 0; i < R; i++)
	{ // loops through row
		for (int j = 0; j < R; j++){ // loops through column in a specific row
			mat[i][j] = rand() % (upper - lower + 1) + lower;
			printf("%d ", mat[i][j]); // to display the row
		}
		printf("\n");
	}
}

int main(){
	int mat[5][5] = {0};
	displayMatrix(mat);
	printf("The above is the random adjacency matrix");
	return 0;
}