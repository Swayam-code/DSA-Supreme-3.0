//Doubly Linked List
#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;

        //constructor
        Node(int value){
            data = value;
            prev = NULL;
            next = NULL;
        }
};

void insertAtHead(int value, Node* &head, Node* &tail){
    //LL is empty
    if(head == NULL && tail ==NULL){
        Node* newNode = new Node(value);
        head= newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        Node* newNode = new Node(value);
        newNode -> next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int value, Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        //LL is empty
        Node* newNode = new Node(value);
        head= newNode;
        tail = newNode;
    }
    else{
        //LLL is not empty
        Node * newNode = new Node(value);
        tail -> next = newNode;
        newNode-> prev = tail;
        tail = newNode;
    }
}

int getLength(Node* &head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(int position, int value, Node* &head, Node* &tail){
    int len = getLength(head);
    if(position == 1 ){
        insertAtHead(value,head,tail);
    }
    else if(position = len+1){
        insertAtTail(value,head,tail);
    }
    else{
        //insert at middle of LL
        Node* temp = head;
        for(int i=0; i< position-2;i++){
            temp = temp->next;
        }
        //create a node
        Node* newNode = new Node(value);
        //set forward point
        Node* forward = temp-> next;
        //set the pointers
        newNode-> prev = temp;

    }
}

void print(Node* head){
    Node* temp = head;
    while( temp!= NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void printReverse(Node* tail){
    Node* temp = tail;
    while(temp!= NULL){
        cout <<temp->data <<"->";
        temp = temp->prev;
    }
    cout <<"NULL" << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(10,head,tail);
    print(head);
    insertAtTail(20,head,tail);
    print(head);
    insertAtTail(30,head,tail);
    print(head);

    // insertAtHead(10,head,tail);
    // print(head);
    // insertAtHead(20,head,tail);
    // print(head);
    // insertAtHead(30,head,tail);
    // print(head);

    printReverse(tail);
    
    return 0;
}
