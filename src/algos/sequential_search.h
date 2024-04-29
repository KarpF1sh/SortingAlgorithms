#ifndef SEQ_SEARCH_H
#define SEQ_SEARCH_H

#include <vector>

class sequential_search
{
public:
    void run();
private:
    int sequentialSearch(const std::vector<int>& data, int key);
    std::vector<int> generateTestData(int size);
};

#endif