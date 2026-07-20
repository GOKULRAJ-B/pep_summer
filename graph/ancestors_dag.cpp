//https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/?envType=problem-list-v2&envId=graph
class Solution {
public:
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &j : edges){
            adj[j[0]].push_back(j[1]);
            indegree[j[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<set<int>> an(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j : adj[node]){
                an[j].insert(node);
                an[j].insert(an[node].begin(),an[node].end());
                indegree[j]--;
                if(indegree[j]==0) q.push(j);  
            }
        }
        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(an[i].begin(), an[i].end());
        }

        return ans;
        
    }
};