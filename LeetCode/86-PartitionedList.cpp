#include <iostream>

using namespace std;
//LeetCode 86 - PartitionList
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
        void partitionList(int x){
//This is to ensure there is more than 1 node in the LinkedList
            if(head == nullptr || head->next == nullptr) return;
//We made dummy nodes as placeholders (The zeros don't reallly mean anything but the value)
            Node dummy1(0);
            Node dummy2(0);
//Here we make pointers to reference the dummy nodes.
            Node* prev1 = &dummy1;
            Node* prev2 = &dummy2;
 //Made a pointer for the head node
            Node* current = head;
//Here we're iterating through the linkedList while the current pointer is not null
            while(current != nullptr){
//Here if the value we go through is less than x we store it in dummy1 which has prev1 pointer
                if(current->value < x){
                    prev1->next =current;
                    prev1 = current;
//Here if the value is >=x then we store it in dummy2 as the pointer for it is prev2.
                }else{
                    prev2->next =current;
                    prev2 = current;
                }
//Here we continue the loop through the current pointer
                current = current->next;
            }
//Here since prev2 is the greater digits we make the last next point to null
            prev2->next = nullptr;
//Here prev1 connects to the dummy2 list
            prev1->next = dummy2.next;
//Here we set the head to dummy1 making it the starting point of the list.
            head =dummy1.next;
            
        }