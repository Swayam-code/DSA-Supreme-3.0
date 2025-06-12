// 2. Add Two Numbers
// Solved
// Medium
// Topics
// Companies
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse linked list
Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to insert at beginning (no tail needed)
Node* insertAtHead(Node* head, int digit) {
    Node* newNode = new Node(digit);
    newNode->next = head;
    return newNode;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    // Step 1: Reverse both lists
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    Node* ans = NULL;
    int carry = 0;
    
    // Step 2: Add numbers
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = 0;
        if(l1 != NULL) {
            val1 = l1->data;
            l1 = l1->next;
        }
            
        int val2 = 0;
        if(l2 != NULL) {
            val2 = l2->data;
            l2 = l2->next;
        }
            
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;
        
        // Insert at head (reverse order)
        ans = insertAtHead(ans, digit);
    }
    
    return ans;
}

int main() {
    // Create first number: 342 (represented as 2->4->3)
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    // Create second number: 465 (represented as 5->6->4)
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    cout << "First number: ";
    printList(head1);
    cout << "Second number: ";
    printList(head2);

    Node* result = addTwoNumbers(head1, head2);
    cout << "Result: ";
    printList(result);

    return 0;
}