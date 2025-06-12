#include<iostream>
using namespace std;

int main (){
    //Control flow : if, else, switch, for, while, do while

    int budget;
    cout << "Enter your budget: ";

    //input from user
    cin >> budget;

    if(budget > 2000000){
        cout << "You can buy a Scorpio" << endl;
    }
    
    return 0;
}