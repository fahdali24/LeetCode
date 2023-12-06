#include "InsertionSort.h"

//InsertionSort
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        // Store the value of the current element in a temp variable
        int temp = array[i];
        // Initialize j to be one index behind i
        int j = i - 1;
        // Shift elements to the right until the correct position for temp is found
        while (j > -1 && temp < array[j]) {
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}