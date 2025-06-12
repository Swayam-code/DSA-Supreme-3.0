#include<iostream>
using namespace std;

class Queue{
    private : 
        int *arr;
        int front;
        int rear;
        int n;
    public :
         Queue(int size){
                arr = new int[size];
                n = size;
                front = -1;
                rear = -1;
          }

          void push(int data){
                if(rear == n-1){
                 cout << "Queue is full" << endl;
                 return;
                }
                rear++;
                arr[rear] = data;
                if(front == -1){
                 front++;
                }
          }
          void pop(){
                if(front == -1 || front > rear){
                 cout << "Queue is empty" << endl;
                 return;
                }
                
                arr[front] = -1;
                front++;
          }
          
          int getSize(){
                return rear - front + 1;
          }
          
          int getFront(){
                 if(front == -1 || front > rear){
                    cout << "Queue is empty" << endl;
                    return -1;
                }
                return arr[front];
           }

           int getRear(){
                if(front == -1 || front > rear){
                    cout << "Queue is empty" << endl;
                    return -1;
                }
                return arr[rear];
           }

           bool isEmpty(){
                if(front == -1 || front > rear){
                    return true;
                }
                return false;
           }
     

};

int main(){

    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    //get size
    cout << "Size of queue is: " << q.getSize() << endl;
    //front element
    cout << "Front element is: " << q.getFront() << endl;
    q.push(50);
    cout << "Front element is: " << q.getFront() << endl;
    //rear element
    cout << "Rear element is: " << q.getRear() << endl;
    q.push(60); // Queue is full

    //pop
    q.pop();
    cout << q.getSize() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop(); // Queue is empty
    cout << q.getSize() << endl;
    q.pop(); // Queue is empty

    //isEmpty
    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }
    return 0;
}