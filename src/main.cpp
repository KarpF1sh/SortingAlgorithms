#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to perform sequential search
int sequentialSearch(const std::vector<int>& data, int key) {
    // Using std::vector<int>::size_type to avoid comparison between signed and unsigned integers
    for (std::vector<int>::size_type i = 0; i < data.size(); ++i) {
        if (data[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to generate test data
std::vector<int> generateTestData(int size) {
    std::vector<int> data;
    for (std::vector<int>::size_type i = 1; i <= static_cast<std::vector<int>::size_type>(size); ++i) {
        data.push_back(2 * i - 1); // Inserting odd integers
    }
    return data;
}

int main() {
    int dataSize;
    std::cout << "Enter the size of the data: ";
    std::cin >> dataSize;

    // Generate test data
    std::vector<int> testData = generateTestData(dataSize);

    // Print the generated data
    std::cout << "Generated Data: ";
    for (auto i = testData.begin(); i != testData.end(); ++i) {
        std::cout << *i << " ";
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
        srand(time(0)); // Seed for random number generation
        key = rand() % (2 * dataSize + 1); // Random number between 0 and 2n
    }

    // Perform sequential search
    int index = sequentialSearch(testData, key);

    // Output the result
    if (index != -1) {
        std::cout << "Key " << key << " found at index " << index << std::endl;
    } else {
        std::cout << "Key " << key << " not found" << std::endl;
    }

    return 0;
}