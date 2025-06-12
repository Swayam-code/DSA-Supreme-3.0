//----------------TRIE----------------
// Trie is a tree-like data structure that is used to store a dynamic set of strings, where the keys are usually strings.
#include<iostream>
#include<unordered_map>
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

int main(){
    TrieNode* root = new TrieNode('-'); // root node with null character
    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "coder");
    insertIntoTrie(root, "code");
    insertIntoTrie(root, "coding");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "cat");
    insertIntoTrie(root, "bat");
    insertIntoTrie(root, "ball");
    insertIntoTrie(root, "batman");
    insertIntoTrie(root, "football");

    bool ans = searchTrie(root, "coding");
    if(ans) {
        cout << "Present in the trie" << endl;
    } else {
        cout << "Not Present in the trie" << endl;
    }

    deleteWord(root, "bat");
    ans = searchTrie(root, "batman");
    if(ans) {
        cout << "Present in the trie" << endl;
    } else {
        cout << "Not Present in the trie" << endl;
    }

    return 0;
}