// ======================================================================
// Name        : assign_5.cpp
// Author      : Omkar Sonawane
// Description : This program implements a function template for the 
//               selection sort algorithm that can sort both integer and
//               float arrays.
// ======================================================================

#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void inputArray(T arr[], int size) {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(T arr[], int size) {
    cout << "Sorted array:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Sorting an integer array
    int intSize;
    cout << "Enter the number of integer elements: ";
    cin >> intSize;

    int intArray[intSize];  // Dynamic array allocation
    inputArray(intArray, intSize);
    selectionSort(intArray, intSize);
    outputArray(intArray, intSize);

    // Sorting a float array
    int floatSize;
    cout << "Enter the number of float elements: ";
    cin >> floatSize;
    float* floatArray = new float[floatSize];
    inputArray(floatArray, floatSize);
    selectionSort(floatArray, floatSize);
    outputArray(floatArray, floatSize);
    delete[] floatArray;

    return 0;
}
