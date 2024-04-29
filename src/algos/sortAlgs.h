#ifndef SORT_H
#define SORT_H

#include <vector>

class sortAlgs
{
public:
    static void insertionSort(std::vector<int>& arr, int& comparisons, int& assignments);
    static void mergeSort(std::vector<int>& arr, int left, int right, int& comparisons, int& assignments);
    static void quicksort(std::vector<int>& arr, int low, int high, int& comparisons, int& assignments);
private:
    static void merge(std::vector<int>& arr, int left, int mid, int right, int& comparisons, int& assignments);
};

#endif