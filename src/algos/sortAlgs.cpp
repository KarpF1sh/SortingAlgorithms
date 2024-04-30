#include "sortAlgs.h"
#include "timer.h"
#include <vector>

// Insertion sort algorithm
void sortAlgs::insertionSort(std::vector<int>& arr, int& comparisons, int& assignments) {
    // Get the size of the array
    int n = arr.size();

    // Loop through the array
    for (int i = 1; i < n; ++i) {

        // Key element is the current element
        int key = arr[i];

        // Previous element
        int j = i - 1;

        // If the previous element is greater than the key element
        while (j >= 0 && arr[j] > key) {
            // Move the previous element to the next position
            arr[j + 1] = arr[j];
            // Decrement j
            --j;

            // Increment comparison and assigment counter
            ++comparisons;
            ++assignments;
        }

        // Insert the key element to the correct position
        arr[j + 1] = key;
        // Increment assignment counter
        ++assignments;
    }
}

// Merge sort algorithm
void sortAlgs::mergeSort(std::vector<int>& arr, int left, int right, int& comparisons, int& assignments) {
    // If left index is less than right index
    if (left < right) {
        // Calculate mid index
        int mid = left + (right - left) / 2;

        // recursively call mergeSort
        mergeSort(arr, left, mid, comparisons, assignments);
        mergeSort(arr, mid + 1, right, comparisons, assignments);
        // Call merge function
        merge(arr, left, mid, right, comparisons, assignments);
    }
}

// Merge function for merge sort
void sortAlgs::merge(std::vector<int>& arr, int left, int mid, int right, int& comparisons, int& assignments) {
    // Calculate the size of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create two subarrays
    std::vector<int> L(n1), R(n2);

    // Copy the elements to the subarrays
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the two subarrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
        // Increment comparison and assignment counter
        ++comparisons;
        ++assignments;
    }

    // Copy the remaining elements of L and R
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
        // Increment assignment counter
        ++assignments;
    }

    // Copy the remaining elements of R
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
        // Increment assignment counter
        ++assignments;
    }
}

// Quicksort algorithm
void sortAlgs::quicksort(std::vector<int>& arr, int low, int high, int& comparisons, int& assignments) {
    // If low index is less than high index
    if (low < high) {

        // Partition the array
        int pivot = arr[high];
        int i = low - 1;

        // Loop through the array
        for (int j = low; j <= high - 1; ++j) {
            // If the current element is less than the pivot
            if (arr[j] < pivot) {
                // Increment i and swap the elements
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        // Swap the pivot element
        std::swap(arr[i + 1], arr[high]);

        // Increment assignment counter
        int partitionIndex = i + 1;

        // Recursively call quicksort
        quicksort(arr, low, partitionIndex - 1, comparisons, assignments);
        quicksort(arr, partitionIndex + 1, high, comparisons, assignments);
    }
}