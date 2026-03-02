/*Write a menu driven program in C to perform the following operations on Matrix. Assume the contents
are integer. Check the necessary condition for performing the addition and multiplication operations.
(a) Initialize
(b) Addition
(c) Multiplication.*/
#include <stdio.h>

#define MAX 100

void initializeMatrix(int matrix[MAX][MAX], int rows, int cols)
{
  printf("Enter the elements in the matrix: \n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
  printf("Matrix: \n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }
}

void multiplyMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB)
{
  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < colsB; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < colsA; k++)
      {
        result[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
}


int main() {
  int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
  int rowsA, colsA, rowsB, colsB;

  printf("Enter the number of rows and columns for Matrix A: ");
  scanf("%d %d", &rowsA, &colsA);
  initializeMatrix(matrixA, rowsA, colsA);

  printf("Enter the number of rows and columns for Matrix B: ");
  scanf("%d %d", &rowsB, &colsB);
  initializeMatrix(matrixB, rowsB, colsB);

  if (rowsA == rowsB && colsA == colsB)
  {
    addMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("Result of Matrix Addition:\n");
    displayMatrix(result, rowsA, colsA);
  }
  else
  {
    printf("Matrix addition cannot be performed. Dimensions do not match.\n");
  }

  if (colsA == rowsB)
  {
    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
    printf("Result of Matrix Multiplication:\n");
    displayMatrix(result, rowsA, colsB);
  }
  else
  {
    printf("Matrix multiplication cannot be performed. Number of columns in Matrix A must equal number of rows in Matrix B.\n");
  }

  return 0;
}
