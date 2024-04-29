#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

class searchAlgs
{
public:
    static int binarySearch(const std::vector<int>& data, int key, int& comparisons);
    static int sequentialSearch(const std::vector<int>& data, int key, int& comparisons);
};

#endif
