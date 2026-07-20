
//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void left(Node* root, vector<int> &result){
        if(root==NULL) return;
        if(root->left || root->right) result.push_back(root->data);
        if(root->left) left(root->left,result);
        else if(root->right) left(root->right,result);
    }
    void leaf(Node* root, vector<int> &result){
        if(root==NULL) return;
        if(!root->left && !root->right) result.push_back(root->data);
        leaf(root->left,result);
        leaf(root->right,result);
    }
    void right(Node* root, vector<int> &result){
        if(root==NULL) return;
        if(root->right) right(root->right,result);
        else if(root->left) right(root->left,result);
        
        if(root->left || root->right) result.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        result.push_back(root->data);
        left(root->left,result);
        if(root->left || root->right) leaf(root,result);
        right(root->right,result);
        return result;
    }
};