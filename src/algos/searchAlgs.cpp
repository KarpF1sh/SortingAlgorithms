#include "searchAlgs.h"
#include "timer.h"
#include "utils.h"
#include <iostream>
#include <vector>

// Binary search algorithm
int searchAlgs::binarySearch(const std::vector<int>& data, int key, int& comparisons) {
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

// Sequential search algorithm
int searchAlgs::sequentialSearch(const std::vector<int>& data, int key, int& comparisons) {
    // Use size_type to compare with vector size to avoid comparison between signed and unsigned integers
    // Loop thorugh the vector and compare each element with the key
    for (std::vector<int>::size_type i = 0; i < data.size(); ++i) {

        // increment comparisons
        comparisons++;

        // Compare element with key
        if (data[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}