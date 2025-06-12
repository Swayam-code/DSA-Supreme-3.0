#include<iostream>
#include<stack>
using namespace std;

//H.W. - find the middle element of stack
void middleElement(stack<int>& s, int count, int size){
    //base case
    if(count == size/2){
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    //store the top element -> 1 case mai karunga
    int top = s.top();
    s.pop();

    //recursive call
    middleElement(s, count + 1, size);

    //push the stored element back -> backtracking
    s.push(top);
}

void insertAtBottom(stack<int>& s, int value){
    //base case
    if(s.empty()){ 
        s.push(value);
        return;
    }

    //store the top element -> 1 case mai karunga
    int top = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, value);

    //push the stored element back -> backtracking
    s.push(top);
}


int main(){

    //insertion at Bottom
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
   
    int value = 43;
    insertAtBottom(s, value);

    // middleElement(s, 0, s.size());
    // cout << endl;

    //traversing the stack
    cout << "Stack elements are: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;


    //priniting in reverse order
    // stack<char> s;
    // string name = "amitwala";

    // //insertion of characters into stack
    // for(int i = 0; i < name.length(); i++){
    //     char ch = name[i];
    //     s.push(ch);
    // }

    // //retrieving characters from stack
    // while(!s.empty()){
    //     char ch = s.top();
    //     cout << ch;
    //     s.pop();
    // }

    return  0;
}