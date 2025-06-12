#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TrieNode {
public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) {
        value = data;
        isTerminal = false;
    }
};

void insertIntoTrie(TrieNode* root, string word) {
    //base case -> string empty ho jaayegi
    if(word.length() == 0) {
        //word khatam ho gaya
        root->isTerminal = true;
        return;
    }

    //1 case mai solve krta hun
    //baaki recursion kar lega
    char ch = word[0];
    TrieNode* child;

    //present hai toh waha chale jao
    //absent hai to create karo
    if(root->children.count(ch) == 1) {
        child = root->children[ch];
    } else {
        //absent
        child = new TrieNode(ch);
        //link
        root->children[ch] = child;
    }

    //baaki recursion karlega
    insertIntoTrie(child, word.substr(1));
}

bool searchTrie (TrieNode* root, string word) {
    //base case -> string empty ho jaayegi
    if(word.length() == 0) {
        //return true if it is terminal
        return root->isTerminal; 
    }

    //1 case mai solve krta hun
    //baaki recursion kar lega
    char ch = word[0];
    TrieNode* child;

    //present hai toh waha chale jao
    //absent hai to return false
    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    } 
    else {
        return false; //absent
    }

    //baaki recursion karlega
    bool recursionAns =  searchTrie(child, word.substr(1));
    return recursionAns; //return the result of recursion
}

void deleteWord(TrieNode* root, string word) {
    //base case -> string empty ho jaayegi
    if(word.length() == 0) {
        //word khatam ho gaya
        root->isTerminal = false;
        return;
    }

    //1 case mai solve krta hun
    //baaki recursion kar lega
    char ch = word[0];
    TrieNode* child;

    //present hai toh waha chale jao
    //absent hai to return false
    if(root->children.find(ch) != root->children.end()) {
        //present
        //waha leke jao
        child = root->children[ch];
    } 
    else {
        //absent, nothing to delete
        return; 
    }

    //baaki recursion karlega
    deleteWord(child, word.substr(1));

    //if child is not terminal and has no children, we can delete it
    if(!child->isTerminal && child->children.size() == 0) {
        delete child; //delete the child node
        root->children.erase(ch); //remove the link from parent to child
    }
}

void storeString(TrieNode* root, vector<string> &ans, string output) {
    //base case
    if(root->isTerminal) {
        //word khatam ho gaya, output mein store kar do
        ans.push_back(output);
        //no need for return , baaki words nhi banenge
    }

    //1 case main karleta hun
    for(auto i : root->children) {
        //it.first is the character
        //it.second is the child node
        char ch  =i.first;
        TrieNode* child = i.second;

        //append the character to output
        output.push_back(ch);

        //baaki recursion kar leta hun
        storeString(child, ans, output);

        //backtrack
        output.pop_back();
    }    
}

void findWordsWithPrefix(TrieNode* root, string prefix, vector<string>& ans) {
    //base case
    if(prefix.length() == 0) {
        //prefix khatam ho gaya, ab root se saare words nikaal lo
        // ab iss last node ke niche jitni bhi strings ban sakti hai,
        //sabko create kardo
        string temp = "";
        storeString(root,ans,temp);

       return;
    }

    //1 case hum karlenge
    char ch = prefix[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    } else {
        //absent, no words with this prefix
        return;
    }

    //baaki recursion karlega
    findWordsWithPrefix(child, prefix.substr(1), ans);
    
}

vector<vector<string>> getSuggestions(TrieNode* root, string prefix) {
    vector<vector<string>> ans;
    string temp = "";
    
    for(int i = 0; i< prefix.length(); i++) {
        vector<string> tempAns;
        char currChar = prefix[i];
        temp.push_back(currChar);

        //find the child node for this character
        findWordsWithPrefix(root, temp, tempAns);
        //store the ans in ans vector
        //add prefix in tempAns
        for(int j = 0; j < tempAns.size(); j++) {
            tempAns[j] = temp + tempAns[j]; // Append the prefix to each found word
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main(){
    TrieNode* root = new TrieNode('-'); // root node with null character
    
    insertIntoTrie(root, "babbar");
    insertIntoTrie(root, "baba");
    insertIntoTrie(root, "babu");
    insertIntoTrie(root, "baby");
    insertIntoTrie(root, "bala");

    string prefix = "bab";
    vector<vector<string>> ans = getSuggestions(root, prefix);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    // string prefix = "bal";
    // vector<string> ans;
    // // Find all words with the given prefix
    // findWordsWithPrefix(root, prefix, ans);
    // // Print the found words    
    // for(size_t i = 0; i < ans.size(); i++) {
    //     string str = prefix + ans[i];
    //     ans[i] = str; // Append the prefix to each found word
    //     cout << ans[i] << " " << endl;
    // }

    // //input -> bal 
    // // b -> ?
    // // ba -> ?
    // // bal -> ?

    return 0;
}