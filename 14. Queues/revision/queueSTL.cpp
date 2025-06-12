#include<iostream>
#include <queue>
using namespace std;

int main(){
    //doubly ended queue
    deque<int> dq;
    //insert
    dq.push_front(10);
    //10 
    dq.push_front(20);
    //10 20
    dq.push_front(30);
    //10 20 30
    dq.push_back(40);
    //40 10 20 30 
    dq.push_back(50);
    //50 40 10 20 30
    //size
    cout << "Size of deque: " << dq.size() << endl;
    //check if empty
    if(dq.empty()){
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    cout << "Front element: " << dq.front() << endl;    
    cout << "Back element: " << dq.back() << endl;

    //removal
    dq.pop_front();
    cout << "Front element after pop: " << dq.front() << endl;
    dq.pop_back();
    cout << "Back element after pop: " << dq.back() << endl;

    // queue<int> q;
    // //insert
    // q.push(10);
    // q.push(20);
    // q.push(30); 
    // q.push(40);

    // //front element
    // cout << "Front element: " << q.front() << endl;
    // //removal
    // q.pop();
    // cout << "Front element after pop: " << q.front() << endl;
    // //size
    // cout << "Size of queue: " << q.size() << endl;
    // //check if empty
    // if(q.empty()){
    //     cout << "Queue is empty" << endl;
    // } else {
    //     cout << "Queue is not empty" << endl;
    // }

    // //rear element
    // cout << "Rear element: " << q.back() << endl;

    //printing
    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    return 0;
}