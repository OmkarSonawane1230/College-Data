"""

Program Name: Assignment No. 6
Author: Omkar Sonawane
Description: This program is implementation of Assignment No. 6 [Quick Sort Algorithm].

"""

def quick_sort(arr):

    def partition(low, high):
        pivot = arr[high]
        i = low - 1

        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def quick_sort_recursive(low, high):
        if low < high:
            pi = partition(low, high)
            quick_sort_recursive(low, pi - 1)
            quick_sort_recursive(pi + 1, high)

    quick_sort_recursive(0, len(arr) - 1)
    return arr

def display_top_five_scores(arr):

    top_five = arr[-5:] if len(arr) >= 5 else arr
    print("\n\nTop Five Scores:")

    for score in reversed(top_five):
        print(f"{score:.2f}")

# Main program starts
percentages = [67.5, 82.3, 90.1, 75.0, 88.6, 79.2, 94.3, 84.5, 71.4, 69.8, 91.2]

sorted_percentages = quick_sort(percentages)
print("Sorted by Quick Sort:")
for i in sorted_percentages:
    print(i, ' ', end='')

display_top_five_scores(sorted_percentages)