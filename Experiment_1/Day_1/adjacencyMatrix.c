#include<stdio.h>

#define R 5


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
			printf("%d ", mat[i][j]); // to display the row
		}
		printf("\n");
	}
}

int main(){
	int mat[5][5] = {0}; // initialised the array

	printf("The adjacency matrix is the following: \n");
	// row 1
	defEdge(mat, 0, 1);
	defEdge(mat, 0, 2);
	defEdge(mat, 0, 3);
	defEdge(mat, 0, 4);

	// row 2
	defEdge(mat, 1, 0);
	defEdge(mat, 1, 2);
	defEdge(mat, 1, 3);
	defEdge(mat, 4, 4);

	// row 3
	defEdge(mat, 2, 0);
	defEdge(mat, 2, 1);
	defEdge(mat, 2, 3);

	// row 4
	defEdge(mat, 3, 0);
	defEdge(mat, 3, 1);
	defEdge(mat, 3, 2);
	defEdge(mat, 3, 4);


	// row 5
	defEdge(mat, 4, 0);
	defEdge(mat, 4, 1);
	defEdge(mat, 4, 3);

	displayMatrix(mat);
	
	return 0;


}