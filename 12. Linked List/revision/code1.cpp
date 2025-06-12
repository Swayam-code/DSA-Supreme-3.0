#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int value){
            this ->data = value;
            this ->next = NULL;
        }
};

void print(Node* head){
    //temp is pointed to head
    Node* temp = head;
    while(temp!=NULL){
        cout << temp-> data <<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}

Node* insertAtTail(int value, Node* &head, Node* &tail){
    //LL is empty -> head = NULL;
    //tail = NULL;
    //it means we are creating first node at LL
    if(head == NULL && tail == NULL){
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: head to point to newNode
        head = newNode;
        //step 3: tail to point to newNode
        tail = newNode;
    }
    else{
        //LL is not empty
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: connect tail next to newNode
        tail -> next = newNode;
        //step 3: tail to point to newNode
        tail = newNode;
    }
    return head;

}

//returns head of the linked list
Node* insertAtHead(int value, Node* &head, Node* &tail){
    //LL is empty -> head = NULL;
    //tail = NULL;
    //it means we are creating first node at LL
    if(head == NULL && tail == NULL){
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: head to point to newNode
        head = newNode;
        //step 3: tail to point to newNode
        tail = newNode;
    }
    else{
        //LL is not empty
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: connect newNode next to head
        newNode -> next = head;
        //step 3: head to point to newNode
        head = newNode;
    }
    return head;

}

Node* insertAtPosition(int value, int position, Node* &head, Node* &tail){
    //assume -> valid position input
    int length = getLength(head);
    
    if(position == 1){
        //insert at head
        head = insertAtHead(value, head, tail);
    }
    else if(position == length + 1){
        //insert at tail
        head = insertAtTail(value, head, tail);
    }
    else{
        //insert at middle
        Node* temp = head;
        for(int i=1; i<position-2; i++){
            temp = temp -> next;
        }
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: connect newNode next to temp next
        newNode -> next = temp -> next;
        //step 3: connect temp next to newNode
        temp -> next = newNode;
    }
    return head;
}

bool search(Node* head, int target){
    Node* temp = head;
    while(temp != NULL){
        //check if target is found
        if(temp -> data == target){
            return true;
        }
        //move to next node
        temp = temp -> next;
    }
    //target not found
    return false;
}

//HW-1 . Return exact position of target
int searchPosition(Node* head, int target){
    Node* temp = head;
    int position = 1;
    while(temp != NULL){
        //check if target is found
        if(temp -> data == target){
            return position;
        }
        //move to next node
        temp = temp -> next;
        position++;
    }
    //target not found
    return -1;
}

Node* deleteNode(int position, Node* &head, Node* &tail){
    //assume -> valid position input
    //empty LL
    if(head == NULL){
        return head;
    }
    //single node LL
    if(head -> next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return head;
    }

    //multiple node LL
    //deletion at head
    if(position == 1){
        //delete head
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    //any other position
    else{
        //delete middle node
        Node* prev = head;
        for(int i=1; i<position-2; i++){
            prev = prev -> next;
        }
        Node* curr = prev -> next;
        Node* forward = curr -> next;
        prev -> next = forward;
        curr -> next = NULL;
        delete curr;
    }
    return head;
}

// HW.2- Delete by value
Node* deleteByValue(int value, Node* &head){
    //assume -> valid position input
    //empty LL
    if(head == NULL){
        return head;
    }
    //single node LL
    if(head -> data == value && head -> next == NULL){
        Node* temp = head;
        head = NULL;
        delete temp;
        return head;
    }

    //multiple node LL
    //deletion at head
    if(head -> data == value){
        //delete head
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    //any other position
    else{
        Node* prev = head;
        while(prev -> next != NULL && prev -> next -> data != value){
            prev = prev -> next;
        }
        if(prev -> next != NULL){
            Node* curr = prev -> next;
            Node* forward = curr -> next;
            prev -> next = forward;
            curr -> next = NULL;
            delete curr;
        }
    }
    return head;
}

int main(){
     
    Node* head = NULL;
    Node* tail = NULL;
    //LL is empty
    head = insertAtTail(101, head, tail);
    //  print(head);
     //101 -> NULL
    head = insertAtTail(102, head, tail);
    //  print(head);
     //101 -> 102 -> NULL
    head = insertAtTail(103, head, tail);
    //  print(head);
     //101 -> 102 -> 103 -> NULL 

    head = insertAtPosition(104, 2, head, tail);
    //  print(head); 
        //101 -> 104 -> 102 -> 103 -> NULL

    head = insertAtPosition(105, 1, head, tail);
    //  print(head); 
        //105 -> 101 -> 104 -> 102 -> 103 -> NULL

    head = insertAtPosition(106, 6, head, tail);
     print(head); 
        //105 -> 101 -> 104 -> 102 -> 103 -> 106 -> NULL

    // cout <<search(head, 104) << endl; //1    
    // cout << "the exact position of target is: " << searchPosition(head, 104) << endl; //3

    // deleteNode(1, head, tail);
    //  print(head); 
    //     //101 -> 104 -> 102 -> 103 -> 106 -> NULL
    // deleteNode(3, head, tail);    
    //  print(head); 
    //         //101 -> 104 -> 103 -> 106 -> NULL
    // deleteNode(4, head, tail);       
    //     print(head); 
    //             //101 -> 104 -> 103 -> NULL 

    deleteByValue(104, head);
     print(head); 
     //105->101->102->103->106->NULL
    deleteByValue(105, head); 
     print(head); 
     //101->102->103->106->NULL
        


    // Node* head = NULL;
    // Node* tail = NULL;
    // //LL is empty
    // head = insertAtHead(10, head, tail);
    //  print(head);
    // //10 -> NULL
    // head = insertAtHead(20, head, tail);
    //  print(head);
    // //20 -> 10 -> NULL
    // head = insertAtHead(30, head, tail);
    //  print(head);
    // //30 -> 20 -> 10 -> NULL

    // print(head);

    //stack
    // Node first;
    //dynamic memory
    // Node* first = new Node(10); //Linked List Creation

    return 0;
}