#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
#include <iostream>

class insertion_sort
{
public:
    void run();
private:
    std::vector<int> generateRandomData(int size, int maxValue);
    void printArraySlice(const std::vector<int>& arr, int start, int end);
    void insertionSort(std::vector<int>& arr);
};

#endif