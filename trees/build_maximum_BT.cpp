//https://leetcode.com/problems/maximum-binary-tree/?envType=problem-list-v2&envId=dhzqd2jm
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
        for(int i : nums){
            TreeNode* cur = new TreeNode(i);
            while(!st.empty() && i>st.top()->val){
                cur->left = st.top();
                st.pop();
            }
            if(!st.empty()){
                st.top()->right = cur;
            }
            st.push(cur);
        }
        while(st.size()>1){
            st.pop();
        }
        return st.top();
    }
};