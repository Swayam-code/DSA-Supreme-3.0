#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int value){
            this -> data = value;
            this -> next = NULL;
        }
};

Node* insertAtHead(int value, Node* &head, Node* &tail){
    //LL is empty-> Head and Tail both point at Tail
    //creating first node of LL
    if(head == NULL && tail == NULL){
        //step1 : create a new node
        Node* newNode = new Node(value);
        //step2: head ->node
        head = newNode;
        //step3: tail->node
        tail = newNode;
    }
    //LL is not empty
    else{
        //step1 : create new node
        Node* newNode = new Node(value);
        //step2: newnode->headnode
        newNode-> next = head;
        //step3: head ->update to newnode
        head = newNode;
    }
    return head;
}

Node* insertAtTail(int value, Node* &head, Node* &tail){
    //LL is empty
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head= newNode;
        tail= newNode;
    }
    //LL is not empty
    else{
        Node* newNode = new Node(value);
        //connect tail to new node
        tail->next = newNode;
        //update tail
        tail = newNode;
    }
    return head;
}

int getLength(Node* head){
    int len = 0;
    Node* temp =head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertatPosition(int position, int value, Node* &head, Node* &tail){
    //assumption -> valid positions inputs given
    int length = getLength(head);

    //3 different cases
    //insert at head
    if(position == 1){
        //insert at head
        head= insertAtHead(value, head, tail);
    }
    
    //insert at tail
    else if(position == length+1){
        //insert at tail
        head = insertAtTail(value, head, tail);
    }
    //insert in between
    else{
        Node* temp = head;
        for(int i=0;i< position-2; i++){
            temp= temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

}

void print(Node* head){
    //temp is pointed to head
    Node* temp = head;
    while(temp!=NULL){
        cout << temp-> data <<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool searchLL(int target, Node* head){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == target) return true;
        temp= temp->next;
    }
    return false;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    head = insertAtTail(101, head, tail);
    print(head);
    
    head = insertAtTail(201, head, tail);
    print(head);
    
    head = insertAtTail(301, head, tail);
    print(head); 
    
    insertatPosition(1,15, head, tail);
    print(head);
    
    insertatPosition(4,20, head, tail);
    print(head);
    
    insertatPosition(3,45, head, tail);
    print(head);
    cout<< searchLL(201, head) << endl;
    
    //Initialize LL as empty
    // Node* head = NULL;
    // Node* tail = NULL;

    

    // Node* head = NULL;
    // Node* tail = NULL;

    // head = insertAtHead(10, head, tail);
    // print(head);
    
    // head = insertAtHead(20, head, tail);
    // print(head);
    
    // head = insertAtHead(30, head, tail);
    // print(head);


    //stack allocation
    //Node first;

    //dynamic memory allocation ->  Linked List
    // Node* first = new Node(10);
    
    return 0;
}