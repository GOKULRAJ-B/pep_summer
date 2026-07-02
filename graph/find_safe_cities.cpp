//https://leetcode.com/problems/find-eventual-safe-states/?envType=problem-list-v2&envId=graph
class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &state, int node){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node] = 1;
        for(auto i : graph[node]){
            if(!dfs(graph,state,i)) return false;
        }
        state[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        vector<int> state(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(dfs(graph,state,i)) result.push_back(i);
        }
        return result;
    }
};