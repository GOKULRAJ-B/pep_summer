//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/?envType=problem-list-v2&envId=dhzqd2jm
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
    void helper(TreeNode* root, int &sum){
        if(!root) return;
        if(root->val%2==0){
            if(root->left && root->left->left){
                sum+=root->left->left->val;
            }
            if(root->left && root->left->right){
                sum+=root->left->right->val;
            }
            if(root->right && root->right->left){
                sum+=root->right->left->val;
            }
            if(root->right && root->right->right){
                sum+=root->right->right->val;
            }
            
        }
        helper(root->left,sum);
        helper(root->right,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
    }
};