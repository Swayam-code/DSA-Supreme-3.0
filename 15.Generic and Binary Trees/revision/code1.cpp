#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL; 
        }
};

Node* createTree(){
        // cout << "Enter the value of the node : ";
        int val;
        cin >> val;

        if (val == -1) {
            return NULL;
        }
        else{
            //valid value
            Node* root = new Node(val);
            //1 case maine kar liya, baaki left and right recursion sambhal lega
            // cout << "Enter the left child of " << val << ": ";
            root->left = createTree();
            // cout << "Enter the right child of " << val << ": ";
            root->right = createTree();
            return root;
        }
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //NLR -> Node, Left, Right
    //N
    cout << root->data << " ";
    //L -> Left Subtree
    preOrderTraversal(root->left);
    //R -> Right Subtree
    preOrderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //LNR -> Left, Node, Right
    //L
    inorderTraversal(root->left);
    //N
    cout << root->data << " ";
    //R
    inorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //LRN -> Left, Right, Node
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout << root->data << " ";
}

//Left to right level order traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //Using a queue to perform level order traversal
    queue<Node*> q;
    //initially state maintain
    q.push(root);
    q.push(NULL); // to mark the end of the first level
    
    //logic -> step A , B and C
    while (!q.empty()) {
        //A: Get the front element
        Node* current = q.front();
        q.pop();
        if(current == NULL) {
            //iska mtlb level khatam ho gaya
            cout << endl; 
            if(!q.empty()) {
                //Agar queue mein abhi bhi elements hain, toh next level ke liye NULL insert kar do
                q.push(NULL);
            }
        }
        else{
            //B: Print the current node's data
            cout << current->data << " ";
            
            //C: Add the left and right children to the queue
            //iske bachhe kha lo -> queue mein insert kar do
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        
    }
}

//HW -1 : Right to left level order traversal
void rightToLeftLevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //Using a queue to perform level order traversal
    queue<Node*> q;
    //initially state maintain
    q.push(root);
    q.push(NULL); // to mark the end of the first level
    
    //logic -> step A , B and C
    while (!q.empty()) {
        //A: Get the front element
        Node* current = q.front();
        q.pop();
        if(current == NULL) {
            //iska mtlb level khatam ho gaya
            cout << endl; 
            if(!q.empty()) {
                //Agar queue mein abhi bhi elements hain, toh next level ke liye NULL insert kar do
                q.push(NULL);
            }
        }
        else{
            //B: Print the current node's data
            cout << current->data << " ";
            
            //C: Add the right and left children to the queue (reverse order)
            //iske bachhe kha lo -> queue mein insert kar do
            if (current->right != NULL) {
                q.push(current->right);
            }
            if (current->left != NULL) {
                q.push(current->left);
            }
        }
        
    }
}

int main() {
    Node* root ;
    root = createTree();
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1 
    //level order traversal ->
    //10
    //50 30
    //40 20
    cout << "Level Order Traversal of the tree is: " << endl;
    levelOrderTraversal(root);
    cout << "Right to Left Level Order Traversal of the tree is: " << endl;
    rightToLeftLevelOrderTraversal(root);
    cout << endl;
    // cout << "Root node value: " << root->data << endl;
}