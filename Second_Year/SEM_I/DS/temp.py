def print_matrix(matrix):
    # Step 1: Determine the maximum width of any element in the matrix
    max_width = 0
    for row in matrix:
        for item in row:
            # Calculate width of the current element
            item_width = len(str(item))
            # Update max_width if the current item is wider
            if item_width > max_width:
                max_width = item_width

    # Step 2: Print each row with aligned columns
    for row in matrix:
        for item in row:
            # Print each item with right alignment and padding to max_width
            print(f"{item:>{max_width}}", end=' ')
        print()  # Move to the next line after printing the row

# Example matrices
A = [
    [1, 22, 333],      # First row
    [4444, 55, 6],     # Second row
    [7, 8, 9]          # Third row
]

B = [
    [12, 34],         # First row
    [56, 78],         # Second row
    [90, 1]           # Third row
]

print("Matrix A:")
print_matrix(A)

print("Matrix B:")
print_matrix(B)
