#include "LongestSequence.h"
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
// LeetCode - 128 LongestConsecutiveSequence
//Solution:
int longestConsecutiveSequence(const vector<int>& nums) {
//Created a set called numSet and fill it with all the numbers from nums
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak =0;
    for(int num : numSet){
// If 'num - 1' is not in 'numSet', then 'num' can be the starting point of a new consecutive sequence.
        if (numSet.find(num - 1) == numSet.end()){
            int currentNum = num;
            int currentStreak = 1;
// While 'currentNum + 1' exists in 'numSet', keep extending the streak by 1 and updating 'currentNum'.
            while(numSet.find(currentNum + 1) != numSet.end()){
                currentNum++;
                currentStreak++;
            }
//After exiting the while loop, we update the longest streak if the current streak is longer.
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
    
}