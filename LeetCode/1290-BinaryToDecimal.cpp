#include <iostream>

using namespace std;
//LeetCode - 1290 BinaryToDecimal 
class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
        
        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
//This is the solution
//The formula is the left index multiplied by 2 then added by the value of a 0 or 1.
        int binaryToDecimal(){
//We start with 'num' initialized to 0, this will hold our
// converted decimal value as we traverse the binary number.
            int num =0;
            Node* current = head;
//Iteration through the LinkedList
            while(current != nullptr){
                num = num *2;
                num = num + current->value;
                current = current ->next;
            }
            return num;
        }
//Example binary 110 = 6 
//The 110 is taken in and read normally from left to right in this loop not right to left
//which is how binary numbers are typically converted.