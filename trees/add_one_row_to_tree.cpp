
//https://leetcode.com/problems/add-one-row-to-tree/?envType=problem-list-v2&envId=dhzqd2jm
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
    TreeNode* createNode(int val,TreeNode* l, TreeNode* r){
        TreeNode* newnode = new TreeNode(val);
        newnode->left = l;
        newnode->right = r;
        return newnode;
    }
    void helper(TreeNode* root, int val, int depth, int currDepth){
        if(currDepth+1==depth){
            root->left = createNode(val, root->left,NULL);
            root->right = createNode(val, NULL, root->right);
            return;
        }
        if(root->left) helper(root->left,val,depth,currDepth+1);
        if(root->right) helper(root->right,val,depth,currDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            return createNode(val,root,NULL);
        }
        helper(root,val,depth,1);
        return root;
    }
};