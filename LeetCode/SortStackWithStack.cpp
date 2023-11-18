#include "SortStack.h"

//Sort Stack using Stack.

//solution:
void sortStack(stack<int>& inputStack) {
//Made additional stack to help sort.
    stack<int> additionalStack;
//In this loop it's popping elements from inputStack and comparing them with additionalStack
//and we keep track of the popped value by using temp as a placeholder.
    while(!inputStack.empty()){
        int temp = inputStack.top();
        inputStack.pop();
//Here the comparison happens and if the top of additionalStack is > temp then it's pushed
//into the inputStack, popped out of the additionalStack, and temp is then pushed to additionalStack. This keeps happening till numbers are sorted.
        
        while(!additionalStack.empty() && additionalStack.top() > temp){
            inputStack.push(additionalStack.top());
            additionalStack.pop();
        }
        additionalStack.push(temp);
    }
//This ensures that all values in additionalStack are put into the inputStack
//The order sorts it's self out as iterations are made so the last additionas are sorted when added
    while(!additionalStack.empty()){
        inputStack.push(additionalStack.top());
        additionalStack.pop();
    }
}