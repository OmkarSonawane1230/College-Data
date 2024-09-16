"""

Program Name: Assignment No. 4
Author: Omkar Sonawane
Description: This program is implementation of Assignment No. 4 [Searching Algorithms].

"""

def linear_search(arr, target):
    """ Linear search function """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def sentinel_search(arr, target):
    """ Sentinel search function """
    n = len(arr)
    last = arr[-1]
    arr[-1] = target

    i = 0
    while arr[i] != target:
        i += 1

    arr[-1] = last
    if i < n - 1 or arr[-1] == target:
        return i
    return -1

def binary_search(arr, target):
    """ Binary search function """
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def fibonacci_search(arr, target):
    """ Fibonacci search function """
    n = len(arr)
    
    fib_prev_prev = 0  # F(n-2)
    fib_prev = 1       # F(n-1)
    fib_current = fib_prev + fib_prev_prev  # F(n)

    while fib_current < n:
        fib_prev_prev = fib_prev
        fib_prev = fib_current
        fib_current = fib_prev + fib_prev_prev

    offset = -1

    while fib_current > 1:
        index = min(offset + fib_prev_prev, n - 1)

        if arr[index] < target:
            fib_current = fib_prev
            fib_prev = fib_prev_prev
            fib_prev_prev = fib_current - fib_prev
            offset = index
        elif arr[index] > target:
            fib_current = fib_prev_prev
            fib_prev = fib_prev - fib_prev_prev
            fib_prev_prev = fib_current - fib_prev
        else:
            return index

    # Final check for the last element
    if fib_prev and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    return -1


# Main program starts
roll_numbers = [102, 108, 115, 123, 134, 145, 156, 167, 178, 189]

# Sorting roll numbers for binary and Fibonacci search
sorted_roll_numbers = sorted(roll_numbers)

print("Sorted Roll Numbers:", sorted_roll_numbers)

target = int(input("Enter the roll number to search: "))

index = linear_search(roll_numbers, target)
val = f"is at {index}." if (index != -1) else f"not found."
print(f"Linear Search: Roll No. {target}", val)

index = sentinel_search(roll_numbers, target)
val = f"is at {index}." if (index != -1) else f"not found."
print(f"Sentinel Search: Roll No. {target}", val)

index = binary_search(sorted_roll_numbers, target)
val = f"is at {index}." if (index != -1) else f"not found."
print(f"Binary Search: Roll No. {target}", val)

index = fibonacci_search(sorted_roll_numbers, target)
val = f"is at {index}." if (index != -1) else f"not found."
print(f"Fibonacci Search: Roll No. {target}", val)
