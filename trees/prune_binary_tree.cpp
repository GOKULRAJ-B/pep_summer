//https://leetcode.com/problems/binary-tree-pruning/?envType=problem-list-v2&envId=dhzqd2jm
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
    TreeNode* remove(TreeNode* root){
        if(root==NULL) return NULL;
        root->left = remove(root->left);
        root->right = remove(root->right);
        
        if(!root->left && !root->right  && root->val==0) return NULL;
        return root;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        return remove(root);
    }
};