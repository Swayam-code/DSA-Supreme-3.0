#include<iostream>
#include<stack>
using namespace std;


int main(){
    //creation
    stack<int> s;
    //insertion
    s.push(10);
    s.push(20);
    s.push(30);
    //size
    cout << "size of stack is: " << s.size() << endl; //3

    //check empty or not
    if(s.empty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "stack is not empty" << endl;
    }
    //peek
    cout << "top element of stack is: " << s.top() << endl; //30
    //removal
    s.pop();
    cout << "top element of stack after pop is: " << s.top() << endl; //20
    return 0;
}