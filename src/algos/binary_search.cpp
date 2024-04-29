#include "binary_search.h"
#include "timer.h"
#include <iostream>

int binary_search::sequentialSearch(const std::vector<int>& data, int key, int& comparisons) {
    // Use size_type to compare with vector size to avoid comparison between signed and unsigned integers
    // Loop thorugh the vector and compare each element with the key
    for (std::vector<int>::size_type i = 0; i < data.size(); ++i) {
        comparisons++;
        if (data[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int binary_search::binarySearch(const std::vector<int>& data, int key, int& comparisons) {
    // Predefined variables for binary search
    int low = 0;
    int high = data.size() - 1;

    // Loop until low is less than or equal to high
    while (low <= high) {

        // Calculate mid index
        int mid = low + (high - low) / 2;
        // increment comparisons
        comparisons++;

        // Compare mid element with key
        if (data[mid] == key) {
            return mid; // Return index if key is found
        } else if (data[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
}

std::vector<int> binary_search::generateTestData(int size) {
    std::vector<int> data;
    // Loop to insert odd integers
    for (int i = 1; i <= size; ++i) {
        data.push_back(2 * i - 1); // Inserting odd integers
    }
    return data;
}

int binary_search::generateRandomKey(int dataSize) {
    // Seed for random number generation
    srand(time(0));
    return rand() % (2 * dataSize + 1); // Random number between 0 and 2n
}

void binary_search::runPerformanceComparison(int dataSize, int repetitions) {
    // Generate test data
    std::vector<int> testData = generateTestData(dataSize);

    // Timer object
    Timer timer;

    // Variables to store elapsed time and comparisons
    double elapsedTime;
    int comparisons;

    //
    std::cout << "Sequential Search:\n";
    for (int i = 0; i < repetitions; ++i) {
        int key = generateRandomKey(dataSize);
        comparisons = 0;
        int index = sequentialSearch(testData, key, comparisons);
        elapsedTime = timer.elapsed_time();
        std::cout << "Status: " << (index != -1 ? "Successful" : "Unsuccessful") << "\n";
        std::cout << "Elapsed per search: " << elapsedTime << "\n";
        std::cout << "Comparisons per search: " << comparisons << "\n";
        std::cout << "Searches: " << repetitions << "\n";
    }

    std::cout << "\nBinary Search:\n";
    for (int i = 0; i < repetitions; ++i) {
        int key = generateRandomKey(dataSize);
        comparisons = 0;
        int index = binarySearch(testData, key, comparisons);
        elapsedTime = timer.elapsed_time();
        std::cout << "Status: " << (index != -1 ? "Successful" : "Unsuccessful") << "\n";
        std::cout << "Elapsed per search: " << elapsedTime << "\n";
        std::cout << "Comparisons per search: " << comparisons << "\n";
        std::cout << "Searches: " << repetitions << "\n";
    }
}

void binary_search::run() {
    int dataSize, repetitions;
    std::cout << "Enter the size of the data: ";
    std::cin >> dataSize;
    std::cout << "Enter the number of repetitions: ";
    std::cin >> repetitions;

    runPerformanceComparison(dataSize, repetitions);
}