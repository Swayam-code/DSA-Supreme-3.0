#include <iostream>
#include <queue>
using namespace std;

class Node{
    public :
      int data;
      Node *left;
      Node *right;

     Node(int val){
         data = val;
         left = NULL;
         right = NULL;
     } 
};

//  Time Complexity : O (logn)
void buildBST(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }
    if(val <= root->data){
        // If the value is less than the root's data, go to the left subtree
        buildBST(root->left, val);
    } else {
        // If the value is greater than or equal to the root's data, go to the right subtree
        buildBST(root->right, val);
    }
}

Node* createTree(){
    Node* root = NULL;
    int val;
    cin >> val; 

    while( val != -1){
        buildBST(root, val);
        cin >> val;
    }
    return root;
}

void levelOrderTraversal(Node* root){
    if(root == NULL) return;

    // Using a queue to perform level order traversal
    queue<Node*> q;
    q.push(root);
    q.push(NULL); 

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout << endl; 
            if(!q.empty()) q.push(NULL); 
        } else {
            cout << front->data << " "; 
            if(front->left) q.push(front->left); 
            if(front->right) q.push(front->right); 
        }
    }
}

void preOrderTraversal(Node* root){
    // Pre-order traversal: node, left, right (NLR)
    if(root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    // In-order traversal: left, node , right (LNR)
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    // Post-order traversal: left, right, node (LRN)
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int getMin(Node* root){
    if(root == NULL) return -1; // Return -1 if the tree is empty
    while(root->left != NULL){
        root = root->left;
    }
    //the extreme left node is the minimum in a BST
    return root->data ;
}

int getMax(Node* root){
    if(root == NULL) return -1; // Return -1 if the tree is empty
    while(root->right != NULL){
        root = root->right;
    }
    //the extreme right node is the maximum in a BST
    return root->data;
}

bool searchInBST(Node* root, int key){
    // Base case: if the tree is empty
    if(root == NULL) return false; 

    if(root->data == key) {
        return true; // Key found
    }

    else{
        // If the key is less than the root's data, search in the left subtree
        if(key < root->data) {
            bool leftAns =  searchInBST(root->left, key);
            if(leftAns == true)
                return true;
        } 
        
        else {
            // If the key is greater than the root's data, search in the right subtree
            bool rightAns =  searchInBST(root->right, key);
            if(rightAns == true)
                return true;
        }
    }
    return false; // Key not found
}


int main(){
    Node* root = createTree();
    //100 20 70 30 50 90 110 -1
    cout << endl;
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "Pre-order Traversal: " ;
    preOrderTraversal(root);
    cout << endl;

    //Observation: In-order traversal of a BST gives sorted order of elements
    cout << "In-order Traversal: " ;
    inOrderTraversal(root);
    cout << endl;
    cout << "Post-order Traversal: " ;
    postOrderTraversal(root);
    cout << endl;

    cout << "Minimum value in the BST: " << getMin(root) << endl;
    cout << "Maximum value in the BST: " << getMax(root) << endl;
    bool searchAns = searchInBST(root, 5);
    if(searchAns) {
        cout << "Node found in the BST." << endl;
    } else {
        cout << "Node not found in the BST." << endl;
    }
    return 0;
}