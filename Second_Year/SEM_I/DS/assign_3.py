"""

Program Name: Assignment No. 3
Author: Omkar Sonawane
Description: This program is implementation of Assignment No. 3 [Operation of matrices].

"""

# Program starts
def print_matrix(matrix):  
    print()  
    max_width = 0
    for row in matrix:
        for item in row:            
            item_width = len(str(item))            
            if item_width > max_width:
                max_width = item_width
    
    for row in matrix:
        for item in row:            
            print(str(item).rjust(max_width), end=' ')
        print()  
    print()

def add_matrices(A, B):
    result = []

    for i in range(len(A)):
        row = []
        for j in range(len(A[0])):
            row.append(A[i][j] + B[i][j])
        result.append(row)

    return result

def subtract_matrices(A, B):
    result = []

    for i in range(len(A)):
        row = []
        for j in range(len(A[0])):
            row.append(A[i][j] - B[i][j])
        result.append(row)
    
    return result

def multiply_matrices(A, B):
    rows_A = len(A)
    cols_A = len(A[0])
    cols_B = len(B[0])
    result = []

    for i in range(rows_A):
        row = []
        for j in range(cols_B):
            value = 0
            for k in range(cols_A):
                value += A[i][k] * B[k][j]
            row.append(value)
    
        result.append(row)

    return result

def transpose_matrix(matrix):
    result = []

    for i in range(len(matrix[0])):
        row = []
        for j in range(len(matrix)):
            row.append(matrix[j][i])

        result.append(row)

    return result

A = [
    [5, 2, 7],
    [1, 3, 2],
    [8, 9, 4]
]

B = [
    [7, 1, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print("Matrix A:")
print_matrix(A)

print("Matrix B:")
print_matrix(B)

print("Addition: A + B")
addition = add_matrices(A, B)
print_matrix(addition)

print("Subtraction: A - B")
subtraction = subtract_matrices(A, B)
print_matrix(subtraction)

print("Multiplication: A * B")
multiplication = multiply_matrices(A, B)
print_matrix(multiplication)

print("Transpose of A:")
transpose = transpose_matrix(A)
print_matrix(transpose)