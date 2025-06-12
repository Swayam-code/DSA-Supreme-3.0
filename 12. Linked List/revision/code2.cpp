#include <iostream>
using namespace std;
//doubly linked list

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* insertAtHead(int value, Node* &head, Node* &tail) {
    //LL is empty
    if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    } else {
        //LL is not empty
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node * insertAtTail(int value, Node* &head, Node* &tail) {
    //LL is empty
    if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    } else {
        //LL is not empty
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return head;
}

Node* insertAtAnyPosition(int position, int value, Node* &head, Node* &tail) {
    //assume -> valid position input
    int len = getLength(head);

    //insert at head
    if (position == 1) {
        insertAtHead(value, head, tail);
    } 
    //insert at tail
    else if (position == len + 1) {
        insertAtTail(value, head, tail);
    }
    else {
        //insert at middle of LL
        Node* temp = head;
        for (int i = 0; i < position - 2; i++) {
            temp = temp->next;
        }
        //create a node
        Node* newNode = new Node(value);
        //set forward point
        Node* forward = temp->next;
        //set the pointers
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next = forward;
        forward->prev = newNode;
    }
    return head;
}

bool search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* deleteNode(int position, Node* &head, Node* &tail) {
    //assume -> valid position input
    //empty LL
    if (head == NULL) {
        return head;
    }
    //single node LL
    if (head->next == NULL) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return head;
    }

    //multiple node LL
    //deletion at head
    if (position == 1) {
        //delete head
        Node* temp = head;
        head = head->next;
        head-> prev = NULL;
        temp ->next = NULL;
        delete temp;
    }
    //delete at tail
    else if (position == getLength(head)) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    //any other position
    else {
        Node* backward = head;
        for (int i = 0; i < position - 2; i++) {
            backward = backward->next;
        }
        Node* curr = backward->next;
        Node* forward = curr->next;

        backward->next = forward;
        forward->prev = backward;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
    return head;    
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printreverse(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    // Your code here
    Node* head = NULL;
    Node* tail = NULL;
    //LL is empty
    head = insertAtHead(10, head, tail);
    //  print(head); // 10->NULL
    head = insertAtHead(20, head, tail);
    //  print(head); // 20->10->NULL
    head = insertAtHead(30, head, tail);
    //  print(head); // 30->20->10->NULL

    // printreverse(tail); // 10->20->30->NULL 

    head = insertAtTail(40, head, tail);
    //  print(head); // 30->20->10->40->NULL
    head = insertAtTail(50, head, tail);
    // print(head); // 30->20->10->40->50->NULL

    head = insertAtAnyPosition(3, 25, head, tail);
    //  print(head); // 30->20->25->10->40->50->NULL  
    head = insertAtAnyPosition(1, 5, head, tail);
      print(head); // 5->30->20->25->10->40->50->NULL

    head = deleteNode(1, head, tail);
      print(head); // 30->20->25->10->40->50->NULL 

    head = deleteNode(3, head, tail);
      print(head); // 30->20->10->40->50->NULL

    head = deleteNode(5, head, tail);
      print(head); // 30->20->10->40->NULL  

    // cout << search(head, 25) << endl; // 1

    return 0;
}