//https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/?envType=problem-list-v2&envId=binary-search-tree
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
    int find_min_equal(int node, vector<int> &elements){
        int ele = -1;
        int start = 0;
        int end = elements.size()-1;
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(elements[mid]<=node){
                ele = elements[mid];
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ele;
    }
    int find_max_equal(int node, vector<int> &elements){
        int ele = -1;
        int start = 0;
        int end = elements.size()-1;
        while(start<=end){
            int mid = start + (end - start) / 2;
            
            if(elements[mid]>=node){
                ele = elements[mid];
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ele;
    }
    
    void inorder(TreeNode* root,vector<int> &elements){
        if(!root) return;
        inorder(root->left,elements);
        elements.push_back(root->val);
        inorder(root->right,elements);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>elements;
        inorder(root,elements);
        vector<vector<int>> result;
        for(int &i : queries){
            result.push_back({find_min_equal(i,elements),find_max_equal(i,elements)});
        }
        return result;
    }
};