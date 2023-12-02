#include "FindPairs.h"
#include <vector>
#include <unordered_set>

using namespace std;
//Set: Find Pairs
//Solution:
vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
    unordered_set<int> mySet;
    vector<vector<int>> pairs;
//We store arr1 values in the set.
    for (int num : arr1){
        mySet.insert(num);
    }
//We loop through arry 2 and find the complement value of each element and check if the set contains the complement then return the pairs.
    for(int num : arr2){
        int complement = target - num;
        if (mySet.find(complement) != mySet.end()){
            pairs.push_back({complement, num});
        }
    }
    return pairs;
}