#ifndef RANDOMS_H
#define RANDOMS_H

#include <vector>

class utils
{
public:
    static int generateRandomKey(int dataSize);
    static std::vector<int> generateOddIntegers(int size);
    static std::vector<int> generateRandomData(int size, int maxValue);
    static void printArraySlice(const std::vector<int>& arr, int start, int end);
};

#endif
