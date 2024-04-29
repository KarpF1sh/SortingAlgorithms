#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "timer.h"

// Function to perform sequential search
int sequentialSearch(const std::vector<int>& data, int key, int& comparisons) {
    for (int i = 0; i < data.size(); ++i) {
        comparisons++;
        if (data[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to perform binary search
int binarySearch(const std::vector<int>& data, int key, int& comparisons) {
    int low = 0;
    int high = data.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;
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

// Function to generate test data
std::vector<int> generateTestData(int size) {
    std::vector<int> data;
    for (int i = 1; i <= size; ++i) {
        data.push_back(2 * i - 1); // Inserting odd integers
    }
    return data;
}

// Function to generate random key
int generateRandomKey(int dataSize) {
    srand(time(0)); // Seed for random number generation
    return rand() % (2 * dataSize + 1); // Random number between 0 and 2n
}

// Function to run performance comparison
void runPerformanceComparison(int dataSize, int repetitions) {
    std::vector<int> testData = generateTestData(dataSize);
    Timer timer;
    double elapsedTime;
    int comparisons;

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

int main() {
    int dataSize, repetitions;
    std::cout << "Enter the size of the data: ";
    std::cin >> dataSize;
    std::cout << "Enter the number of repetitions: ";
    std::cin >> repetitions;

    runPerformanceComparison(dataSize, repetitions);

    return 0;
}