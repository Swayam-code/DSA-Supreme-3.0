#include<iostream>
using namespace std;

class Stack{
    public : 
        int* arr;
        int size;
        int top1;
        int top2;        
        
        Stack(int capacity){
            arr = new int[capacity];
            // Initialize all elements to 0
            for(int i = 0; i < capacity; i++) {
                arr[i] = 0;
            }
            size = capacity;
            top1 = -1;
            top2 = size;
        }

        void push1(int data){
            if(top2 - top1 == 1){
                cout << "Stack overflow" << endl;
                return;
            }
            top1++;
            arr[top1] = data;
        }

        void push2(int data){
            if(top2 - top1 == 1){
                cout << "Stack overflow" << endl;
                return;
            }
            top2--;
            arr[top2] = data;
        }

        void pop1(){
            if(top1 == -1){
                cout << "Stack underflow" << endl;
                return;
            }
            arr[top1] = 0;
            top1--;
        }

        void pop2(){
            if(top2 == size){
                cout << "Stack underflow" << endl;
                return;
            }
            arr[top2] = 0;
            top2++;
        }

        void print(){
            cout << "Top1: " << top1 << endl;
            cout << "Top2: " << top2 << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Stack s(5);
    s.push1(10);
    s.print();
    s.push2(20);
    s.print();
    s.push2(30);
    s.print();

    s.pop1();
    s.print();

    s.push1(40);
    s.print();

    return 0;
}