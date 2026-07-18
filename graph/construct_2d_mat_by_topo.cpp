
//https://leetcode.com/problems/build-a-matrix-with-conditions/?envType=problem-list-v2&envId=graph
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row_topo;
        vector<int>col_topo;
        vector<int>indegree(k);
        vector<vector<int>> adj(k);
        vector<vector<int>> adj1(k);
        vector<vector<int>>result;
        for(auto &i : rowConditions){
            indegree[i[1]-1]++;
            adj[i[0]-1].push_back(i[1]-1);
        }
        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            row_topo.push_back(node);
            for(int &i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        fill(indegree.begin(), indegree.end(), 0);
        for(auto &i : colConditions){
            indegree[i[1]-1]++;
            adj1[i[0]-1].push_back(i[1]-1);
        }
        for(int i=0;i<k;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            col_topo.push_back(node);
            for(int &i : adj1[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(row_topo.size()<k || col_topo.size()<k) return result;
        result.resize(k, vector<int>(k, 0));
        vector<int>row_pos(k);
        vector<int>col_pos(k);
        for(int i=0;i<k;i++){
            row_pos[row_topo[i]] = i;
        }
        for(int i=0;i<k;i++){
            col_pos[col_topo[i]] = i;
        }
        for(int i=0;i<k;i++){
            result[row_pos[i]][col_pos[i]] = i+1;
        }
        return result;
    }
};