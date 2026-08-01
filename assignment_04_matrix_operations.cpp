// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Assignment 4 - Matrix Operations
// This program does 3 things with matrices:
// 1. Transpose a matrix
// 2. Add two matrices
// 3. Multiply two matrices

// functions I will use later
void getMatrix(int m[10][10], int rows, int cols);
void printMatrix(int m[10][10], int rows, int cols);
void transpose(int m[10][10], int rows, int cols, int result[10][10]);
void addMatrix(int a[10][10], int b[10][10], int result[10][10], int rows, int cols);
void multiplyMatrix(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB);

int main() {
    int choice;

    cout << "MATRIX PROGRAM" << endl;
    cout << "1 = Transpose" << endl;
    cout << "2 = Add two matrices" << endl;
    cout << "3 = Multiply two matrices" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) {
        int m[10][10];
        int result[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        getMatrix(m, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(m, rows, cols);

        transpose(m, rows, cols, result);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cols, rows);
    }

    else if (choice == 2) {
        int a[10][10];
        int b[10][10];
        int result[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nFill in Matrix A" << endl;
        getMatrix(a, rows, cols);

        cout << "\nFill in Matrix B" << endl;
        getMatrix(b, rows, cols);

        cout << "\nMatrix A:" << endl;
        printMatrix(a, rows, cols);

        cout << "\nMatrix B:" << endl;
        printMatrix(b, rows, cols);

        addMatrix(a, b, result, rows, cols);

        cout << "\nSum of A and B:" << endl;
        printMatrix(result, rows, cols);
    }

    else if (choice == 3) {
        int a[10][10];
        int b[10][10];
        int result[10][10];
        int rowsA, colsA, rowsB, colsB;

        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;
        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Cannot multiply, columns of A must equal rows of B." << endl;
        } else {
            cout << "\nFill in Matrix A" << endl;
            getMatrix(a, rowsA, colsA);

            cout << "\nFill in Matrix B" << endl;
            getMatrix(b, rowsB, colsB);

            cout << "\nMatrix A:" << endl;
            printMatrix(a, rowsA, colsA);

            cout << "\nMatrix B:" << endl;
            printMatrix(b, rowsB, colsB);

            multiplyMatrix(a, b, result, rowsA, colsA, colsB);

            cout << "\nResult of A times B:" << endl;
            printMatrix(result, rowsA, colsB);
        }
    }

    else {
        cout << "That is not a valid choice." << endl;
    }

    return 0;
}

void getMatrix(int m[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for row " << i << " column " << j << ": ";
            cin >> m[i][j];
        }
    }
}

void printMatrix(int m[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << m[i][j];
        }
        cout << endl;
    }
}

void transpose(int m[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = m[i][j];
        }
    }
}

void addMatrix(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum = sum + a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}




