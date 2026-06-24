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
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        result.push_back(root->val);
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int max = INT_MIN;
            int count = 0;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                    if(front->left->val > max){
                        max = front->left->val;
                    }
                    count++;
                }
                if(front->right){
                    q.push(front->right);
                    if(front->right->val > max){
                        max = front->right->val;
                    }
                    count++;
                }
            }
            if(count!=0) result.push_back(max);
        }
        return result;
    }
};