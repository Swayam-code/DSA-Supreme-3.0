#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void insertNode(Node* &tail, int element, int data) {
    // If list is empty
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    
    // List is not empty
    // Find the element after which to insert
    Node* curr = tail;
    while(curr->data != element) {
        curr = curr->next;
        if(curr == tail) {
            cout << "Element not found" << endl;
            return;
        }
    }
    
    // Create new node
    Node* newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
}

void print(Node* tail) {
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = tail;
    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while(tail != temp);
    cout << endl;
}

int getLength(Node* tail) {
    if(tail == NULL) {
        return 0;
    }
    
    Node* temp = tail;
    int count = 0;
    do {
        count++;
        tail = tail->next;
    } while(tail != temp);
    
    return count;
}

int main() {
    Node* tail = NULL;
    
    // Insert some nodes
    insertNode(tail, 5, 3);  // First node, element doesn't matter
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    
    cout << "Circular Linked List: ";
    print(tail);
    
    cout << "Length of the list: " << getLength(tail) << endl;
    
    return 0;
}
