#include "SubarraySum.h"
//LeetCode - 560 SubArraySum

vector<int> subarraySum(const vector<int>& nums, int target) {
    unordered_map<int, int> sumIndex;
//By including the initial entry in the map, the algorithm correctly handles subarrays starting from the beginning.
    sumIndex[0] = -1;
    int currentSum =0;
    for(int i =0; i<nums.size(); i++){
//Inside the for loop, the value of the current number is added to the currentSum
        currentSum +=nums[i];
        if(sumIndex.find(currentSum - target) != sumIndex.end()){
            return {sumIndex[currentSum - target] + 1, i};
        }
//If the if statement's condition is false, the currentSum and its index (i) are added to the sumIndex map.
        sumIndex[currentSum] = i;
    }
    return {};
}