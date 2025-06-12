#include<iostream>  
using namespace std;

class CircularQueue{
    private:
        int *arr;
        int n;
        int front;
        int rear;
    public:
        CircularQueue(int size){
            this->n = size;
            arr = new int[size];
            for(int i = 0; i < n; i++){
                arr[i] = 0;
            }
            front = -1;
            rear = -1;
        }

        void push(int val){
            //4 cases : overflow, first element, normal flow. circular nature
            // queue is full
            if((front == 0 && rear == n-1) || (front == rear + 1)){
                cout << "Overflow" << endl;
            }
            // first element insert
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            // normal flow
            else if(rear == n-1 && front != 0){
                rear = 0;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // 4cases: underflow, single element, circular nature, normal flow
            if(front == -1 && rear == -1){
                cout<<"Underflow"<<endl;
            }
            // single element
            else if(front==rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // circular nature
            else if(front == n-1){
                arr[front] = -1;
                front = 0;
            }
            // normal case
            else{
                arr[front] = -1;
                front++;
            }
        }

        int getSize(){
            // number of elements inside a queue
            if(front == -1 && rear == -1) return 0;
            else if(rear >= front) return rear - front + 1;
            else return (n - front + rear + 1);
        }

        int getFront(){
            if(front == -1 && rear == -1) cout << "Queue is empty" << endl;
            else return arr[front];
        }

        bool isEmpty(){
            if(front == -1 && rear == -1) return true;
            else return false;
        }

        void printQueue(){
            for(int i = 0; i < n; i++){
                    cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){

    CircularQueue q(5);
    q.push(10);
    q.printQueue();

    q.push(20);
    q.printQueue();

    q.push(30);
    q.printQueue();

    q.push(40);
    q.printQueue();

    q.push(50);
    q.printQueue();

    q.pop();
    q.printQueue();

    q.pop();
    q.printQueue();

    q.push(60);
    q.printQueue();

    q.push(70);
    q.printQueue();

    cout << "the size of the queue is: " << q.getSize() << endl;
    cout << "the front element of the queue is: " << q.getFront() << endl;
    cout << "is the queue empty: " << q.isEmpty() << endl;

    return 0;
}