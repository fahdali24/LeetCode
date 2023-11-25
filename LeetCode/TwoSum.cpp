#include "TwoSum.h"
//LeetCode - 1 TwoSum
//Solution
//Prior to inputting into the map we check then input based on the inital values.
vector<int> twoSum(const vector<int>& nums, int target) {
	unordered_map<int, int> numMap;
 
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int complement = target - num;
// Check if the complement exists in the hashmap
        if (numMap.find(complement) != numMap.end()) {
// If found, return the indices of the elements (hashmap[complement] and i)
            return {numMap[complement], i};
        }
// Otherwise, insert the current element's value as the key and its index as the value
        numMap[num] = i;
    }
// No valid pair found
    return {};
}