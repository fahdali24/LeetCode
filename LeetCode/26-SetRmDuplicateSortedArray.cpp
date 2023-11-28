#include "RemoveDuplicates.h"
#include <vector>
#include <unordered_set>

using namespace std;
//LeetCode - 26 Remove Duplicates from sorted Array
//Solution:
vector<int> removeDuplicates(const vector<int>& myList) {
// Create an empty set called 'uniqueSet'. Sets can't have duplicate items.
// Initialize it with the numbers from 'myList'. This removes duplicates
// automatically because sets only store unique values.

    unordered_set<int> uniqueSet(myList.begin(), myList.end());
    
// Convert 'uniqueSet' back to a list (vector) format. 
// This new list will contain all unique numbers, in no specific order.
// The new list is what gets returned by the function

    return vector<int>(uniqueSet.begin(), uniqueSet.end());
   
}