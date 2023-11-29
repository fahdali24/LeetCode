#include "HasUniqueChars.h"
#include <string>
#include <unordered_set>

using namespace std;
//Set:HasUniqueChars 
//Soultion:
bool hasUniqueChars(const string& str) {
    unordered_set<char> charSet;
 
    for (char ch : str) {
        if (charSet.find(ch) != charSet.end()) {
            return false;
        }
        charSet.insert(ch);
    }
 
    return true;
}