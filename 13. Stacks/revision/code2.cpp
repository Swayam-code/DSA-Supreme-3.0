#include <iostream>
#include <stack>
#include <climits>
using namespace std;

void sortedInsert(stack<int>& s, int value) {
    // Base case
    if(s.empty()){
        s.push(value);
        return;
    }
    
    if (!s.empty() && s.top() < value) {
        s.push(value);
        return;
    }

    // 1 case solve karunga -> Store the top element
    int topElement = s.top();
    s.pop();

    // Recursive call
    sortedInsert(s, value);

    // Push the stored element back
    s.push(topElement);
}

void insertAtBottom(stack<int>& s, int value) {
    // Base case
    if (s.empty()) {
        s.push(value);
        return;
    }

    // 1 case solve karunga -> Store the top element
    int topElement = s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s, value);

    // Push the stored element back
    s.push(topElement);
}

void reverseStack(stack<int>& s) {
    // Base case
    if (s.empty()) {
        return;
    }

    // 1 case solve karunga -> Store the top element
    int topElement = s.top();
    s.pop();

    // Recursive call
    reverseStack(s);

    // Push the stored element back
    insertAtBottom(s, topElement);
}

bool checkSorted(stack<int>& s, int& element1) {
    // Base case
    if (s.empty()) {
        return true;
    }

    // 1 case solve karunga -> Store the top element
    int element2  = s.top();
    s.pop();
    if(element2 < element1) {
        bool result = checkSorted(s, element2);
        // Push the stored element back
        s.push(element2);
        return result;
    }
    // If the current element is not less than the previous one, return false
    else {
        
        return false;
    }
}

void printMiddle(stack<int>& s, int count) {
    // Base case
    if (count == 0) {
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    // 1 case solve karunga -> Store the top element
    int top = s.top();
    s.pop();
    count--;

    // Recursive call
    printMiddle(s, count);

    // Push the stored element back
    s.push(top);
}   

void print(stack<int>& s) {
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    int value = 43;
    sortedInsert(s, value);
    print(s);

    // print(s);
    // cout << endl;
    // reverseStack(s);
    // print(s);
    // cout << endl;

    // int element1 = INT_MAX;
    // cout  << checkSorted(s, element1) << endl; // 1

    // int count = s.size()/2;
    // printMiddle(s, count);

    return 0;
}

