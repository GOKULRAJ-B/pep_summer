//https://leetcode.com/problems/all-paths-from-source-to-target/?envType=problem-list-v2&envId=graph
class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, int dist, vector<int> &each, vector<vector<int>>&result){
        each.push_back(node);
        if(node == dist){
            result.push_back(each);
            each.pop_back();
            return;
        }
        for(auto &i : graph[node]){
            dfs(graph,i,dist,each,result);
        }
        each.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>result;
        vector<int>e;
        dfs(graph,0,n-1,e,result);
        return result;
    }
};