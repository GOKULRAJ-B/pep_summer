//https://leetcode.com/problems/even-odd-tree/?envType=problem-list-v2&envId=dhzqd2jm
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int currLevel=0;
        while(!q.empty()){
            int a = -1;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                if(currLevel==0 || currLevel%2==0){
                    if(a==-1){
                        a = frontNode->val;
                        if(frontNode->val%2==0) return false;
                    }
                    else{
                        if(frontNode->val%2==0 || frontNode->val<=a) return false;
                        a = frontNode->val;
                    }

                }
                else{
                    if(a==-1){
                        if(frontNode->val%2!=0) return false;
                        a = frontNode->val;
                    }
                    else{
                        if(frontNode->val%2!=0 || frontNode->val>=a) return false;
                        a = frontNode->val;
                    }

                }
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            currLevel++;
        }
        return true;
    }
};