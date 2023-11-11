#include <iostream>

using namespace std;
//ReverseDoublyLinkedList
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
        //Solution
        void reverse(){
            if(length<2)return;
            Node* current = head;
            Node* temp =nullptr;
//In this loop what's happening is we're reversing the order of the nodes direction.
//In this case we're turning the original prev nodes into next nodes to reverse the order.
//We use the temp variable to help us keep track as we iterate through.
            while(current != nullptr){
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
//By the time we go through the loop head and tail will be opposite due to the reversal
//The temp variable will be null due to the changes only occuring in the loop.
//So here we swap the values of head and tail pointers
            temp=head;
            head=tail;
            tail=temp;
        }