#include <iostream>
#include <vector>

// Include test functions
#include "tests.h"

// Main function
int main(){
    int choice;

    // Menu
    do {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << " Input your wanted grade level to run " << std::endl;
        std::cout << "            1, 2, 3, 4 or 5           " << std::endl;
        std::cout << "                                      " << std::endl;
        std::cout << "1: sequential search                  " << std::endl;
        std::cout << "2: binary search and seq comparison   " << std::endl;
        std::cout << "3: insertion sort                     " << std::endl;
        std::cout << "4: quicksort                          " << std::endl;
        std::cout << "5: sorting speed comparison           " << std::endl;
        std::cout << "Type 6 to Quit the program            " << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        // Functions below are from tests.h
        switch(choice) {
            case 1:
                sequential_search();
                break;
            case 2:
                binary_search();
                break;
            case 3:
                insertion_sort();
                break;
            case 4:
                quick_sort();
                break;
            case 5:
                sorting_speed();
                break;
            case 6:
                break;
            default:
                // Invalid choice
                std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }
    } while(choice != 6); // Exit the program when the user enters 6

    return 0;
}