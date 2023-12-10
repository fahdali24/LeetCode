#include <iostream>

using namespace std;

//BST DFS InOrder
class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  This is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
        void DFSInOrder(Node* currentNode) {
    // Check if the left child of the current node exists
    if (currentNode->left != nullptr) {
        // Recursively call the DFSInOrder function on the left child
        DFSInOrder(currentNode->left);
    }
    
    // Print the value of the current node
    cout << currentNode->value << " ";
 
    // Check if the right child of the current node exists
    if (currentNode->right != nullptr) {
        // Recursively call the DFSInOrder function on the right child
        DFSInOrder(currentNode->right);
    }
}

        void DFSInOrder() {
            DFSInOrder(root);
        }

};