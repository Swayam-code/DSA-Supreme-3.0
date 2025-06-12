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

void solve(Node*head, int&carry){
    if(!head) {
        return;
    }
    solve(head->next, carry);

    //1 case
    int sum = head->data + carry;
    int digit = sum % 10;
    carry = sum / 10;
    head->data = digit;

}

Node* add1(Node*head, int carry){
    solve(head, carry);
    if(carry) {
        //insert at head
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }   

    return head;

}

int main(){
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    int carry = 1;
    head = add1(head, carry);

    // Print the updated linked list
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}