#include <iostream>
#include <vector>

#include "sequential_search.h"
#include "binary_search.h"
#include "insertion_sort.h"
#include "performance_quicksort.h"

int main(){
    int choice;

    do {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << " Input your wanted grade level to run " << std::endl;
        std::cout << "            1, 2, 3, 4 or 5           " << std::endl;
        std::cout << "      Type 6 to Quit the program      " << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                sequential_search grade1;
                grade1.run();
                break;
            case 2:
                binary_search grade2;
                grade2.run();
                break;
            case 3:
                insertion_sort grade3;
                grade3.run();
                break;
            case 4:
                performance_quicksort grade4;
                grade4.run();
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }
    } while(choice != 6);

    return 0;
}