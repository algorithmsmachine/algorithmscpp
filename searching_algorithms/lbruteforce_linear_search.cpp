//
// Created by altanai on 09/08/20.
//
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/**
 * Algorithm implementation
 * \param [in] array array to search in
 * \param [in] size length of array
 * \param [in] key key value to search for
 * \returns index where the key-value occurs in the array
 * \returns -1 if key-value not found
 */
int LinearSearch(int *array, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return i;
        }
    }

    return -1;
}

/** main function */
int main() {
    int size;
    std::cout << "\nEnter the size of the Array : ";
    std::cin >> size;

    int *array = new int[size];
    int key;

    // Input array
    std::cout << "\n Enter the Array of " << size << " numbers : ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    std::cout << "\n Enter the number to be searched : ";
    std::cin >> key;

    auto start = high_resolution_clock::now();
    int index = LinearSearch(array, size, key);
    auto stop = high_resolution_clock::now();

    if (index != -1) {
        std::cout << "\n Brute Force Search - Number found at index : " << index;
    } else {
        std::cout << "\n Not found";
    }

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

    delete[] array;
    return 0;
}
