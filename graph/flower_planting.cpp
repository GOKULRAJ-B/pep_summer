//https://leetcode.com/problems/flower-planting-with-no-adjacent/?envType=problem-list-v2&envId=graph

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n,0);
        vector<vector<int>> adj(n);
        for(auto &j : paths){
            adj[j[0]-1].push_back(j[1]-1);
            adj[j[1]-1].push_back(j[0]-1);
        }
        for(int i=0;i<n;i++){
            bool used[5] = {false};
            for(int &j : adj[i]){
                used[color[j]] = true;
            }
            for(int k=1;k<=4;k++){
                if(!used[k]){
                    color[i] = k;
                    break;
                }
            }
        }
        return color;
    }
};