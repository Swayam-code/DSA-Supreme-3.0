#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseInKGroups(queue<int> &q, int k, int count) {
    //T.C = O(n)
    //S.C = O(k)
    // Base case: if the queue is empty or k is 0, return
    if (q.empty() || k <= 0) {
        return;
    }
    // Check if the number of elements in the queue is greater than or equal to k
    if(count >= k){
        //toh mai reverse karunga
        stack<int> st;
        for(int i = 0; i < k; i++){
            //fetch the first k elements from queue
            int element = q.front();
            q.pop();
            st.push(element);
        }

        //fetch k elements from stack and push them to queue
        while(!st.empty()){
            int element = st.top();
            st.pop();
            q.push(element);
        }
        //1 case maine karliya baaki recursion karlega
        reverseInKGroups(q, k, count - k);
    }
    else{
        //count < k
        //as it is queue ke front se utha kar end pe daal do
        for(int i = 0; i < count; i++){
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
}

void reverseQueue(queue<int> &q) {
    //using stack
    stack<int> st;
    // Transfer elements from queue to stack
    while (!q.empty()) {
        int element = q.front();
        q.pop();

        st.push(element);
    }

    //ab tak reverse hogaye honge
    while(!st.empty()){
        int element = st.top();
        st.pop();

        q.push(element);
    }

}

void reverseQueueRec(queue<int> &q) {
    // Base case: if the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Step 1: Dequeue the front element
    int front = q.front();
    q.pop();

    // Step 2: Recursively reverse the remaining queue
    reverseQueueRec(q);

    // Step 3: Enqueue the front element at the back of the reversed queue
    q.push(front);
}

int main() {
    // Your code here
    queue<int> q;
    //insert
    q.push(10);
    q.push(20); 
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);    
    q.push(110);

    int k = 3;
    int count = q.size();
    reverseInKGroups(q, k, count);

    // reverseQueue(q);
    // reverseQueueRec(q);
    // cout << "Reversed queue: ";

    // Print the reversed queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}