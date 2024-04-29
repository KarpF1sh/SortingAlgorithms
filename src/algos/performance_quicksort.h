#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <iostream>

class performance_quicksort
{
public:
    void run();
private:
    std::vector<int> generateRandomData(int size, int maxValue);
    void printArraySlice(const std::vector<int>& arr, int start, int end);
    void quicksort(std::vector<int>& arr, int low, int high);
};

#endif
