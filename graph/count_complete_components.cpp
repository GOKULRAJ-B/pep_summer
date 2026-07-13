//https://leetcode.com/problems/count-the-number-of-complete-components/?envType=problem-list-v2&envId=graph
class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &deg, int &nodes){
        
        vis[node] = 1;
        nodes++;
        deg += adj[node].size();
        for(auto i : adj[node]){
            if(vis[i]==0) dfs(i,adj,vis,deg,nodes);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                int nodes = 0;
                int deg =0;
                dfs(i,adj,vis,deg,nodes);
                int no_edge = deg/2;
                if(no_edge == nodes*(nodes-1)/2) count++;
            }
        }
        return count;
    }
};