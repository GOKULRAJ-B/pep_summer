//https://leetcode.com/problems/maximal-network-rank/?envType=problem-list-v2&envId=graph
class Solution {
public:
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n,vector<int>(n,0));
        vector<int>indegree(n,0);
        for(auto &j : roads){
            adj[j[0]][j[1]] = 1;
            adj[j[1]][j[0]] = 1;
            indegree[j[0]]++;
            indegree[j[1]]++;
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj[i][j]==1 || adj[j][i]==1){
                    ans = max(ans,indegree[i]+indegree[j]-1);
                }
                else{
                    ans = max(ans,indegree[i]+indegree[j]);
                }
            }
        }
        return ans;
    }
};