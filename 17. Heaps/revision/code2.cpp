#include <iostream>
#include <queue>
using namespace std;

int main(){

    //min-heap
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(15);
    //accessing the top element
    cout << "Top element: " << pq.top() << endl; // should print 5
    //removal
    pq.pop(); // removes the top element (5)
    cout << "Top element after pop: " << pq.top() << endl; // should print 10
    
    // //creation
    // priority_queue<int> pq; // max heap by default
    // // insertion
    // pq.push(10);
    // pq.push(5);
    // pq.push(30);
    // pq.push(15);

    // //accessing the top element
    // cout << "Top element: " << pq.top() << endl; // should print 30

    // //removal
    // pq.pop(); // removes the top element (30)
    // cout << "Top element after pop: " << pq.top() << endl; // should print 15
    // pq.pop(); // removes the top element (15)
    // cout << "Top element after another pop: " << pq.top() << endl; // should print 10
    return 0;
}