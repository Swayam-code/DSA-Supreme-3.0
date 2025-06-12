#include<iostream>
using namespace std;

int main(){ 

    string s2="baby";
    string s1="world";
    
    //if equal -> Output : 0
    cout << s1.compare(s2) << endl; // -1

    // string name = "What is your name?";
    // string word = "name?";

    // if(name.find(word) != string::npos){
    //     cout << "Word found" << endl;
    // }
    // else{
    //     cout << "Word not found" << endl;
    // }
    
    // int ans = name.find(word); // returns the index of the first occurrence of word in name
    // cout << ans << endl; // 13


    // cout << name.substr(5); // is your name?
    // cout << name.substr(0, 4) << endl; // What (0->index, 4->length)

    // string fName = "Swayam";
    // string lName = "Kar";

    // string ans = fName + " " + lName;
    // cout << "String is: " << ans << endl;

    // string name = "Maharana Pratap";

    // if(name.empty()){
    //     cout << "String is empty" << endl;  
    // }   
    // else{
    //     cout << "String is not empty" << endl;
    // }

    // auto it = name.begin();
    // while(it != name.end()){
    //     cout << *it << " ";
    //     it++;
    // }
    // cout << name[0] << endl; // M
    // cout << name.at(0) << endl; // M

    // cout <<name.front() << endl; // M
    // cout <<name.back() << endl; // p    
    // cout <<name.length() << endl; // 15


    // string sentence;
    // cout << "Enter the sentence: ";
    // // cin >> sentence;
    // getline(cin, sentence,'\n');
    // cout << "String is: " << sentence << endl;
    //creation
    // string str;

    // str.push_back('a');
    // str.push_back('b');
    // str.push_back('c');
    // str.push_back('d');
    // str.push_back('e');
    // str.pop_back();

    // cout << "String is: " << str << endl;

    // cout << "enter the input: ";
    // //input
    // cin >> str;
    // //output
    // cout << "String is: " << str << endl;
    // //access individual character
    // cout << "First character: " << str[0] << endl;
    

    return 0;
}