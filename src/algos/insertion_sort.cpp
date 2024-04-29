#include <iostream>
#include <vector>
#include "insertion_sort.h"
#include "timer.h"

// Function to generate random integer values
std::vector<int> insertion_sort::generateRandomData(int size, int maxValue) {
    std::vector<int> data;
    for (int i = 0; i < size; ++i) {
        data.push_back(rand() % (maxValue + 1)); // Generate random number between 0 and maxValue
    }
    return data;
}

// Function to print a portion of the array
void insertion_sort::printArraySlice(const std::vector<int>& arr, int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Insertion sort algorithm
void insertion_sort::insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void insertion_sort::run() {
    int dataSize, sliceSize;
    std::cout << "Enter the size of the data: ";
    std::cin >> dataSize;
    std::cout << "Enter the size of the slice to print: ";
    std::cin >> sliceSize;

    // Generate random data
    std::vector<int> data = generateRandomData(dataSize, 10000);

    // Print unsorted slice
    std::cout << "Unsorted slice:\n";
    printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    // Sort the data and measure execution time
    Timer timer;
    insertionSort(data);
    double elapsedTime = timer.elapsed_time();

    // Print sorted slice
    std::cout << "Sorted slice:\n";
    printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    std::cout << "Time taken for sorting: " << elapsedTime << " seconds" << std::endl;
}