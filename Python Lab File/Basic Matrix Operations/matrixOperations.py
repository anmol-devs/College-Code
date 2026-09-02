import numpy as np

print("--- MATRIX OPERATIONS USING NUMPY ---")

# 1. Do Matrices banate hain (Hardcoded for simplicity)
# Ye 2x2 Matrices hain
matrix_A = np.array([
    [1, 2],
    [3, 4]
])

matrix_B = np.array([
    [5, 6],
    [7, 8]
])

print("Matrix A:\n", matrix_A)
print("Matrix B:\n", matrix_B)

# 2. Addition (Jodna)
# Numpy mein seedha '+' use kar sakte hain
add = np.add(matrix_A, matrix_B)
print("\n1. Addition (A + B):\n", add)

# 3. Subtraction (Ghatana)
sub = np.subtract(matrix_A, matrix_B)
print("\n2. Subtraction (A - B):\n", sub)

# 4. Multiplication (Guna) - Dot Product
# Note: '*' use karne se element-wise multiply hota hai.
# Matrix multiplication ke liye 'np.dot()' ya '@' use karte hain.
mul = np.dot(matrix_A, matrix_B)
print("\n3. Multiplication (Dot Product):\n", mul)

# 5. Transpose (Ulta karna)
# Rows ko Columns bana dena
trans = matrix_A.T
print("\n4. Transpose of A:\n", trans)