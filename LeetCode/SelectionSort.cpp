#include "SelectionSort.h"

//SelectionSort Tutorial
void selectionSort(int array[], int size) {
    for(int i = 0; i<size; i++){
        int minIndex = i;
        for(int j = i+1; j<size; j++){
            if(array[j] < array[minIndex]){
                minIndex = j;
            }
        }
        if(i != minIndex){
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

}