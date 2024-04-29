#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include <iostream>

class binary_search
{
public:
    void run();
private:
    int sequentialSearch(const std::vector<int>& data, int key, int& comparisons);
    int binarySearch(const std::vector<int>& data, int key, int& comparisons);
    std::vector<int> generateTestData(int size);
    int generateRandomKey(int dataSize);
    void runPerformanceComparison(int dataSize, int repetitions);
};

#endif

