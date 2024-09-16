"""

Program Name: Assignment No. 5
Author: Omkar Sonawane
Description: This program is implementation of Assignment No. 5 [Sorting Algorithms].

"""

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # Find the minimum element
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr

def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n - i -1):
            if arr[j] > arr[j + 1]:
                # Swap the element
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

    return arr

def display_top_five_scores(arr):
    # Ensure there are at least five scores to display
    top_five = arr[-5:] if len(arr) >= 5 else arr

    print("Top Five Scores:")
    for score in reversed(top_five):
        print(f"{score:.2f}")

# Main program starts
percentages = [67.5, 82.3, 90.1, 75.0, 88.6, 79.2, 94.3, 84.5, 71.4, 69.8, 91.2]

percentages_selection_sort = percentages.copy()
percentages_bubble_sort = percentages.copy()

sorted_selection = selection_sort(percentages_selection_sort)
print("Sorted by Selection Sort:")
display_top_five_scores(sorted_selection)

sorted_bubble = bubble_sort(percentages_bubble_sort)
print("\nSorted by Bubble Sort:")
display_top_five_scores(sorted_bubble)
