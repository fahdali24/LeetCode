#include <iostream>

using namespace std;
//DoublyLinkedListPalindromeChecker
class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
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
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        //This is the solution
        bool isPalindrome() {
           if (length < 2) return true;

           Node* current = head;
           Node* temp = tail;

// Use a while loop to iterate through the linked list
           while (current != nullptr && temp != nullptr) {
// Compare the values of the current and temp nodes
               if (current->value != temp->value) {
                   return false;  // If values are different, it's not a palindrome
               }

               current = current->next;  // Move current to the next node
               temp = temp->prev;       // Move temp to the previous node
           }

           return true;  // If the loop completes, it's a palindrome
}