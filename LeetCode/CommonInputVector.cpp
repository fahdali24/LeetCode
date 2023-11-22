#include "ItemInCommon.h"
//#include <iostream>
//#include <vector>
//#include <unordered_map>
// checks if two input vectors have at least one common item.
bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    std::unordered_map<int, bool> myMap;

    // Populate the map with elements from vect1
    for (int item : vect1) {
        myMap[item] = true;
    }

    // Check if any element from vect2 is in the map
    for (int item : vect2) {
        if (myMap.find(item) != myMap.end()) {
            return true; // Found a common item
        }
    }

    return false; // No common items
}