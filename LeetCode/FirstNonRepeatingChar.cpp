#include "FirstNonRepeatingChar.h"
//LeetCode - 387 First Unique Character in a String

//Solution
char firstNonRepeatingChar(const string& input_string) {
    unordered_map <char, int> charCounts;
    for(char c : input_string){
        charCounts[c]++;
    }
    for(char c : input_string){
        if (charCounts[c]==1){
            return c;
        }
    }
    return '\0';
    
}