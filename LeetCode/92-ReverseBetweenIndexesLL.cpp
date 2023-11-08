#include <iostream>

using namespace std;
//LeetCode - 92 Reverse Between two indexes
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
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        //This is the solution
         void reverseBetween(int m, int n) {
//Checks that LinkedList has more than 1 value.
            if (head == nullptr || head ->next == nullptr) return;
//Make a dummy node incase reversal starts from 0 also helps for edge cases.
            Node* dummy = new Node(0);
            dummy->next = head;
            Node* prev = dummy;
            
//This gets you to the previous node from where we start
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
//Here the reversal occurs whats happening here is we're essentailly breaking the chain
//and rearranging values all pointers keep their values except temp which is reset in the loop.
//The iteration is done twice.
            Node* current = prev->next;
            for (int i = 0; i < n - m; i++) {
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
    
            head = dummy->next;
            delete dummy;
        }