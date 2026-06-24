/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rightSum(int val, vector<int> &v){
        int sum = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]>=val){
                sum = sum + v[i];
            }
        }
        return sum;
    }
    void inorder(TreeNode* root, vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* helper(TreeNode* root, vector<int> &v){
        if(root==NULL) return NULL;
        TreeNode* nroot = new TreeNode(rightSum(root->val,v));
        nroot->left = helper(root->left,v);
        nroot->right = helper(root->right,v);
        return nroot;
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return helper(root,v);
    }
};