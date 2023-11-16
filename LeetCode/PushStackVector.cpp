#include <iostream>
#include <vector>

using namespace std;
//Push a stack that uses a vector
class Stack {
    private:
        vector<int> stackVector;
    
    public:
        vector<int>& getStackVector() {
            return stackVector;
        }
    
        void printStack() {
            for (int i = stackVector.size() - 1; i >= 0; i--) {
                cout << stackVector[i] << endl;
            }
        }
    
        bool isEmpty() {
            return stackVector.size() == 0;
        }
    
        int peek() {
            if (isEmpty()) {
                return int();
            } else {
                return stackVector[stackVector.size() - 1];
            }
        }
    
        int size() {
            return stackVector.size();
        }
        //Solution
        void push(int value){
     // Add the new value to the top of the stack
    // by appending it to the end of the vector
            stackVector.push_back(value);
        }