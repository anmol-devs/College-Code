#include <iostream>
using namespace std;

// Function to add two matrices
void addMatrix(int A[10][10], int B[10][10], int result[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int A[10][10], int B[10][10], int result[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int A[10][10], int B[10][10], int result[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // initialize each element
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int A[10][10], int result[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[j][i] = A[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int A[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[10][10], B[10][10], result[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for Matrix B: ";
    cin >> r2 >> c2;

    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(A, r1, c1);
    cout << "\nMatrix B:\n";
    displayMatrix(B, r2, c2);

    // Addition and Subtraction are possible only if dimensions are same
    if (r1 == r2 && c1 == c2) {
        addMatrix(A, B, result, r1, c1);
        cout << "\nAddition of A and B:\n";
        displayMatrix(result, r1, c1);

        subtractMatrix(A, B, result, r1, c1);
        cout << "\nSubtraction of A and B:\n";
        displayMatrix(result, r1, c1);
    } else {
        cout << "\nAddition/Subtraction not possible (different dimensions)\n";
    }

    // Multiplication is possible if c1 == r2
    if (c1 == r2) {
        multiplyMatrix(A, B, result, r1, c1, c2);
        cout << "\nMultiplication of A and B:\n";
        displayMatrix(result, r1, c2);
    } else {
        cout << "\nMultiplication not possible (columns of A != rows of B)\n";
    }

    // Transpose of Matrix A
    transposeMatrix(A, result, r1, c1);
    cout << "\nTranspose of Matrix A:\n";
    displayMatrix(result, c1, r1);

    return 0;
}