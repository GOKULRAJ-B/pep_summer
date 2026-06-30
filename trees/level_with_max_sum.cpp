//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=problem-list-v2&envId=dhzqd2jm
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxSum = root->val;
        int level = 1;
        int currLevel = 0;
        while(!q.empty()){
            int sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                sum+=frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);

            }
            currLevel++;
            if(sum>maxSum){
                maxSum=sum;
                level=currLevel;
            }
        }
        return level;
    }
};