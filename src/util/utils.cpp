#include "utils.h"
#include <iostream>
#include <vector>

// Function to generate test data
std::vector<int> utils::generateOddIntegers(int size) {
    // New vector to store the data
    std::vector<int> data;
    // Loop to insert odd integers
    for (int i = 1; i <= size; ++i) {
        data.push_back(2 * i - 1); // Inserting odd integers
    }
    return data;
}

// Function to generate random integer values
std::vector<int> utils::generateRandomData(int size, int maxValue) {
    // Seed for random number generation
    srand(time(0));

    std::vector<int> data;
    for (int i = 0; i < size; ++i) {
        // Generate random number between 0 and maxValue
        data.push_back(rand() % (maxValue + 1));
    }
    return data;
}

// Function to print a portion of the array
void utils::printArraySlice(const std::vector<int>& arr, int start, int end) {
    // Loop to print the array elements
    for (int i = start; i <= end; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int utils::generateRandomKey(int dataSize) {
    // Seed for random number generation
    srand(time(0));
    return rand() % (2 * dataSize + 1); // Random number between 0 and 2n
}
