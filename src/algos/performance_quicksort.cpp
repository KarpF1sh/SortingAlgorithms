#include "performance_quicksort.h"
#include "timer.h"

// Function to generate random integer values
std::vector<int> performance_quicksort::generateRandomData(int size, int maxValue) {
    std::vector<int> data;
    for (int i = 0; i < size; ++i) {
        data.push_back(rand() % (maxValue + 1)); // Generate random number between 0 and maxValue
    }
    return data;
}

// Function to print a portion of the array
void performance_quicksort::printArraySlice(const std::vector<int>& arr, int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Quicksort algorithm
void performance_quicksort::quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}

void performance_quicksort::run() {
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

    // Sort the data using Quicksort and measure execution time
    Timer timer;
    quicksort(data, 0, dataSize - 1);
    double elapsedTime = timer.elapsed_time();

    // Print sorted slice
    std::cout << "Sorted slice:\n";
    printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    std::cout << "Time taken for sorting: " << elapsedTime << " seconds" << std::endl;
}