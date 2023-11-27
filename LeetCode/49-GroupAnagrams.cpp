#include "GroupAnagrams.h"
//LeetCode - 49 Group Anagrams
//Solution
vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    unordered_map<string, vector<string>> anagramGroups;
    
//In each string we are sorting the characters of the string in canonical order.
//canonical will contain the characters of the original string, sorted alphabetically.

//This loop processes each string in the input vector by creating its canonical form (formed by sorting its characters) and then adds the original string to its corresponding anagram group in the anagramGroups map. After this loop, the map will contain groups of anagrams, where each group is identified by the canonical form of the strings it contains.
    for (const string& str : strings){
        string canonical = str;
        sort(canonical.begin(), canonical.end());
//The canonical form is then used as a key in the anagramGroups map.
//If a group already exists for this canonical form, the original string is added to that group.
//If no group exists for this canonical form, a new group is created with the original string as its first element.
        anagramGroups[canonical].push_back(str);
    }
//This line declares a vector named result, where each element of the vector is a vector of strings
    vector<vector<string>> result;
    for (const auto& group : anagramGroups){
//adds the vector of strings associated with the current canonical form to the end of the result vector.
        result.push_back(group.second);
        
    }
//The final result vector contains sub-vectors, each representing a group of anagrams. It effectively organizes all anagram groups into a single vector, making it easy to return and work with the grouped anagrams in the calling code.
    return result;
}