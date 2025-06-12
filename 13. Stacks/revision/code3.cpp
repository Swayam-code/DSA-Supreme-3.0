#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

//previousSmallerElement
void previousSmallerElement(stack<int> s, vector<int> &arr, vector<int> &ans){
    int n = arr.size();
    for(int i = 0 ; i < n; i++){
        int element  = arr[i];
        //is element ke liye stack check karna hai
        while(s.top() >= element){
            s.pop();
        }
        //stack top has smaller element
        ans.push_back(s.top());
        //push the current element in the stack
        s.push(element);
    }
}

//nextSmallerElement 
void nextSmallerElement(stack<int> s, vector<int> &arr, vector<int> &ans){
    int n = arr.size();
    for(int i = n-1 ; i >= 0; i--){
        int element  = arr[i];
        //is element ke liye stack check karna hai
        while(s.top() >= element){
            s.pop();
        }
        //stack top has smaller element
        ans.push_back(s.top());
        //push the current element in the stack
        s.push(element);
    }
}

int main(){
    vector<int> v;
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    vector<int> ans;

    stack<int> s;
    s.push(-1); // -1 is the base case for the first element
    
    //previous smaller element
    previousSmallerElement(s, v, ans);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    //next smaller element
    // nextSmallerElement(s, v, ans);
    // reverse(ans.begin(), ans.end());
    // //reverse the ans vector to get the correct order
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }

    return 0;
}
