#include <iostream>
#include <unordered_set>

using namespace std;
//LeetCode -1836 Remove duplicates from an unsorted LinkedList
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
        void removeDuplicates(){
             //Made the list to store unique values
            unordered_set<int> values;
            Node* previous = nullptr;
            Node* current = head;
            //Traverse through the list
            while(current != nullptr){
//If the repeated value is found in the list prior to inserting it then we will remove the
//repeated value from the list and decrement the length.
                if(values.find(current->value) != values.end()){
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                    length--;
//If the value being inserted is not a repeated value then it'll insert it.
                }else{
                    values.insert(current->value);
                    previous = current;
                    current = current->next;
                }
            }
          
        }