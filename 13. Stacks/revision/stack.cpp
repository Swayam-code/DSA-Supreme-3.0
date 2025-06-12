#include <iostream>
using namespace std;

class Stack {
    public :
        int* arr;
        int size;
        int top;

        Stack (int capacity) {
            arr = new int[capacity];
            size = capacity;
            top = -1;
        }

        void push(int data) {
            if (top == size - 1) {
                cout << "Stack overflow" << endl;
                return;
            }
            top++;
            arr[top] = data;
        }

        void pop() {
            if (top == -1) {
                cout << "Stack underflow" << endl;
                return;
            }
            arr[top] = 0;
            top--;
        }

        int getSize() {
            return top + 1;
        }

        bool isEmpty() {
            return top == -1;
        }

        int getTop() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }

        void print() {
            cout << "Stack elements are: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    //creating stack with capacity 5
    Stack s(5);
    s.print();
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    s.push(40);
    s.push(50);
    s.print();
    s.push(60); //stack overflow

    cout << "Size of stack: " << s.getSize() << endl; //5
    cout << "Top element of stack: " << s.getTop() << endl; //50
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; //No

    s.pop();
    s.print(); //10 20 30 40
    s.pop();
    s.print(); //10 20 30
    s.pop();
    s.print(); //10 20
    s.pop();
    s.print(); //10
    s.pop();
    s.print(); //stack is empty
    s.pop(); //stack underflow
    

    return 0;
}