#include "ReverseString.h"
//Stack: Reverse String 

string reverseString(const string& str) {
//Made char stack where letters are stored
//Made string variable for the reversed string to be input.
    stack<char> charStack;
    string reversedString;
//This range-based for loop iterates through each character c in the input string str.
    for(char c : str){
        charStack.push(c);
    }
// Pop characters from the stack and add them to the reversed string
    while(!charStack.empty()){
        reversedString += charStack.top();
        charStack.pop();
    }
    return reversedString;
    
}