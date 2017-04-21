/**  @Author: Thiago Henrique Neves Coelho
  *  Date: 20/04/2017
  *  Algorithm: Matrix Exponentiation by Squaring
  */

#include <cstdio>
#include <stdlib.h>
 
typedef long long int ll;
 
void clearMatrix(ll **matrix, int row) {
	/* Free all allocated memory spaces in the matrix */
	for(int i = 0; i < row; i++) free(matrix[i]);
	free(matrix);
}
 
ll **multiplyMatrix(ll **matrix, ll **matrix2, int row, int col, int _row, int _col) {
	/* Multiply matrix by matrix2 */
	/* The sizes are: matrix(row x col) and matrix2(_row x _col) */
	ll **aux;
 
	aux = (ll **) malloc(sizeof(ll*)*row);
	for(int i = 0; i < row; i++) aux[i] = (ll *) malloc(sizeof(ll)*_col);
	/* aux(row x _col) will be the result of the multiplication */
 
	if(col != _row) {
		puts("Invalid matrix multiplication");
		exit(1);
	}
 
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < _col; j++) {
			aux[i][j] = 0;
			for(int k = 0; k < col; k++) {
				aux[i][j] += matrix[i][k] * matrix2[k][j];
			}
		}
	}
	return aux;
}
 
ll **exponentiate(ll **matrix, int n, int exp) {
	ll **aux, **temp;
 
	aux = (ll **) malloc(sizeof(ll*)*n);
	for(int i = 0; i < n; i++) aux[i] = (ll *) malloc(sizeof(ll)*n);
 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			aux[i][j] = matrix[i][j];
			matrix[i][j] = (i == j ? 1 : 0);
		}
	}
	/* matrix is now matrix^0 (Identity) */
	/* aux stores the matrix to exponentiate itself in the loop */
	
	while(exp > 0) {
		/* Square-And-Multiply Algorithm applied to matrices */
		if(exp&1) {
			temp = matrix;
			matrix = multiplyMatrix(matrix, aux, n, n, n, n); // Multiply
			clearMatrix(temp, n);
		}
		temp = aux;
		aux = multiplyMatrix(aux, aux, n, n, n, n); // Square
		clearMatrix(temp, n);
		exp /= 2;
	}
	clearMatrix(aux, n);
	
	return matrix;
}
