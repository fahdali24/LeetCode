#include "FindDuplicates.h"

//Find and return all the duplicate elements in a given vector of integers.
vector<int> findDuplicates(const vector<int>& nums) {
    //Made the hashmap
    unordered_map<int, int> numCounts;
    //This loop iterates through nums and increments the value associated with the key num by 1. If num was not in the map before
    for (int num : nums) {
        numCounts[num]++;
    }
    //created a vector for the duplicates
    vector<int> duplicates;
    //This is a range-based for loop that iterates over each key-value pair in the numCounts map. entry is a reference to a const pair of the key and value.
    for (const auto& entry : numCounts) {
        if (entry.second > 1) {
            duplicates.push_back(entry.first);
        }
    }
    return duplicates;
}
