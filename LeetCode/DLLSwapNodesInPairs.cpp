#include <iostream>

using namespace std;
//DLLSwapNodesInPairs
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
        //Solution:
        void swapPairs(){
//We make a dummy node for edge cases and assign it's pointers
            Node dummyNode(0);
            dummyNode.next = head;
            Node* previousNode = &dummyNode;
//Loop keeps running as long as there are atleast two more nodes to swap.
            while(head != nullptr && head->next != nullptr){
                Node* firstNode = head;
                Node* secondNode = head->next;
//We first connect previousNode to secondNode.
//Then, we rearrange the next pointers of firstNode and secondNode to swap their positions.
                previousNode->next =secondNode;
                firstNode->next = secondNode->next;
                secondNode->next = firstNode;
                secondNode->prev =previousNode;
                firstNode->prev = secondNode;
//This line ensures that if firstNode->next exists, its prev pointer 
//correctly points back to firstNode
                if(firstNode->next != nullptr){
                    firstNode->next->prev = firstNode;
                }
                head = firstNode->next;
                previousNode = firstNode;
            }
//This sets the head back to the next node of the dummy node.
//We also set prev of the new head to nullptr since there's no node before head.
            head = dummyNode.next;
            if(head) head->prev = nullptr;
            
            
        }