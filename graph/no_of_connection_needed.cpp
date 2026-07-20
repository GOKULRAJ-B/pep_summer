//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/?envType=problem-list-v2&envId=graph
class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        vis[node]=1;
        for(auto &i : adj[node]){
            if(vis[i]==0){
                dfs(adj,vis,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto &j : connections){
            adj[j[0]].push_back(j[1]);
            adj[j[1]].push_back(j[0]);
        }
        vector<int>vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(adj,vis,i);
            }
        }
        return count-1;
    }
};