//https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/?envType=problem-list-v2&envId=dhzqd2jm
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int currLevel = 1;
        while(!q.empty()){
            vector<TreeNode*>v;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                if(currLevel%2==0) v.push_back(frontNode);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            if(currLevel%2==0){
                int i=0, j=v.size()-1;
                while(i<=j){
                    swap(v[i++]->val,v[j--]->val);
                }
            }
            currLevel++;
        }
        return root;
    }
};