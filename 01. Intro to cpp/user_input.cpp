#include <iostream>
#include <limits>
using namespace std;

int main(){
    //Input stream : cin
    //Output stream : cout

    //variable declared
    bool marks ;
    cout << "Enter your marks: ";
    
    //input from user
    cin >> marks; 
    
    // cout << "Your marks are: " << marks << endl;

    //cin.fail() : checks if the input is valid or not
    //cin.ignore() : ignores the invalid input and clears the input buffer
    //getline(cin, name) : takes input from user until newline character is encountered

    if (cin.fail()) {
        cout << "Invalid input! Please enter 0 or 1." << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(100, '\n'); // Clear the input buffer
    } else {
        cout << "Your marks are: " << marks << endl;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //getline
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Your name is: " << name << endl;

    return 0;
}