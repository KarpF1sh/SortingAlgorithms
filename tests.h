#include <iostream>
#include <vector>
#include "utils.h"
#include "searchAlgs.h"
#include "sortAlgs.h"
#include "timer.h"

// Function prototypes

// Perform sequential search
void sequential_search(){
    // Ask the user for the size of the data list
    int dataSize;
    std::cout << "Enter the size of the data list: ";
    std::cin >> dataSize;

    // Generate test data
    std::vector<int> testData = utils::generateOddIntegers(dataSize);

    // Print the generated data
    std::cout << "Generated Data: ";
    for (std::vector<int>::size_type i = 0; i < testData.size(); ++i) {
        std::cout << testData[i] << " ";
    }
    std::cout << std::endl;

    // Choose whether to enter the key or generate it randomly
    char choice;
    std::cout << "Do you want to enter the key manually? (y/n): ";
    std::cin >> choice;

    int key;
    if (choice == 'y' || choice == 'Y') {
        std::cout << "Enter the key value to search for: ";
        std::cin >> key;
    } else {
        // Generate key randomly
        key = utils::generateRandomKey(dataSize);
    }

    // comparison counter
    int comparisons = 0;
    // Perform sequential search
    int index = searchAlgs::sequentialSearch(testData, key, comparisons);

    // Output the result
    if (index != -1) {
        std::cout << "Key " << key << " found at index " << index << ", Comparisons:" << comparisons << std::endl;
    } else {
        std::cout << "Key " << key << " not found, Comparisons:" << comparisons << std::endl;
    }
}

// Perform binary search
void binary_search() {
    // Ask the user for the size of the data list
    int dataSize, repetitions;
    std::cout << "Enter the size of the data list: ";
    std::cin >> dataSize;
    std::cout << "Enter the number of repetitions: ";
    std::cin >> repetitions;

    // Generate test data
    std::vector<int> testData = utils::generateOddIntegers(dataSize);

    // Timer object
    Timer timer;

    // Variables to store elapsed time and comparisons
    double elapsedTime;
    int comparisons;

    // Perform operations for the specified number of repetitions

    std::cout << "Sequential Search:\n";
    for (int i = 0; i < repetitions; ++i) {
        // Generate random key for search
        int key = utils::generateRandomKey(dataSize);

        // Reset the comparison counter
        comparisons = 0;

        // Perform sequential search
        int index = searchAlgs::sequentialSearch(testData, key, comparisons);

        // Get elapsed time
        elapsedTime = timer.elapsed_time();

        // Output the result
        std::cout << "Status: " << (index != -1 ? "Successful" : "Unsuccessful") << "\n";
        std::cout << "Elapsed per search: " << elapsedTime << "\n";
        std::cout << "Comparisons per search: " << comparisons << "\n";
        std::cout << "Searches: " << repetitions << "\n";
    }

    std::cout << "\nBinary Search:\n";
    for (int i = 0; i < repetitions; ++i) {
        // Generate random key for search
        int key = utils::generateRandomKey(dataSize);

        // Reset the comparison counter
        comparisons = 0;

        // Perform binary search
        int index = searchAlgs::binarySearch(testData, key, comparisons);

        // Get elapsed time
        elapsedTime = timer.elapsed_time();

        // Output the result
        std::cout << "Status: " << (index != -1 ? "Successful" : "Unsuccessful") << "\n";
        std::cout << "Elapsed per search: " << elapsedTime << "\n";
        std::cout << "Comparisons per search: " << comparisons << "\n";
        std::cout << "Searches: " << repetitions << "\n";
    }
}

// Perform insertion sort
void insertion_sort() {
    // Ask the user for the size of the data and the slice to print
    int dataSize, sliceSize;
    std::cout << "Enter the size of the data: ";
    std::cin >> dataSize;
    std::cout << "Enter the size of the slice to print: ";
    std::cin >> sliceSize;

    // Generate random data in the range 0 to 10000
    std::vector<int> data = utils::generateRandomData(dataSize, 10000);

    // Print unsorted slice
    std::cout << "Unsorted slice:\n";
    utils::printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    // Sort the data and measure execution time
    Timer timer;

    // Variables to store comparisons and assignments
    int comparisons = 0;
    int assignments = 0;

    // Perform insertion sort
    sortAlgs::insertionSort(data, comparisons, assignments);
    // Get elapsed time
    double elapsedTime = timer.elapsed_time();

    // Print sorted slice
    std::cout << "Sorted slice:\n";
    utils::printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    // Output the result
    std::cout << "Time taken for sorting: " << elapsedTime << " seconds, Comparisons:" << comparisons << ", assigments:" << assignments << std::endl;
}

// Perform merge sort
void performance_comparison() {
    // Ask the user for the size of the data and the slice to print
    int dataSize, sliceSize;
    std::cout << "Enter the size of the data: ";
    std::cin >> dataSize;
    std::cout << "Enter the size of the slice to print: ";
    std::cin >> sliceSize;

    // Generate random data in the range 0 to 10000
    std::vector<int> data = utils::generateRandomData(dataSize, 10000);

    // Print unsorted slice
    std::cout << "Unsorted slice:\n";
    utils::printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    // Sort the data using Quicksort and measure execution time
    Timer timer;

    // Variables to store comparisons and assignments
    int comparisons = 0;
    int assignments = 0;

    // Perform quicksort
    sortAlgs::quicksort(data, 0, dataSize - 1, comparisons, assignments);
    double elapsedTime = timer.elapsed_time();

    // Print sorted slice
    std::cout << "Sorted slice:\n";
    utils::printArraySlice(data, 0, std::min(sliceSize - 1, dataSize - 1));

    // Output the result
    std::cout << "Time taken for sorting: " << elapsedTime << " seconds" << std::endl;
}

// Perform performance comparison
void sorting_speed() {
    // Get speed samples from 100 to 100000 with a step of 100
    for (int i = 100; i < 100000; i = i * 100) {
        // Generate random data from 0 to 10000 with i elements
        std::vector<int> data = utils::generateRandomData(i, 10000);

        // Print the size of the data
        std::cout << i << ":" << std::endl;

        // Timer object
        Timer timer;

        // Insertion Sort
        // Copy the data to another vector
        std::vector<int> insertionData = data;

        // Variables to store comparisons and assignments
        int insertionComparisons = 0;
        int insertionAssigments = 0;
        // Reset the timer
        timer.reset();
        // Perform insertion sort
        sortAlgs::insertionSort(insertionData, insertionComparisons, insertionAssigments);
        // Get the elapsed time
        double insertionTime = timer.elapsed_time();

        // Merge Sort
        // Copy the data to another vector
        std::vector<int> mergeData = data;
        // Variables to store comparisons and assignments
        int mergeComparisons = 0;
        int mergeAssigments = 0;
        // Reset the timer
        timer.reset();
        // Perform merge sort
        sortAlgs::mergeSort(mergeData, 0, i - 1, mergeComparisons, mergeAssigments);
        double mergeTime = timer.elapsed_time();

        // Output results
        std::cout << "insertion_sort\tComparisons:" <<  insertionComparisons << "\tAssigments:" << insertionAssigments << "\tTime:" << insertionTime * 1000 <<  std::endl;
        std::cout << "merge_sort\tComparisons:" << mergeComparisons << "\tAssigments:" << mergeAssigments << "\tTime:" << mergeTime * 1000 << std::endl << std::endl;
    }
}