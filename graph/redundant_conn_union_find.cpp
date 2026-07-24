//https://leetcode.com/problems/redundant-connection/?envType=problem-list-v2&envId=graph
class Solution {
    vector<int>parent,rank;
public:
    int find_p(int node){
        if(parent[node]==node) return node;
        return parent[node] = find_p(parent[node]);
    }
    void union_uv(int u, int v){
        int p_u = find_p(u);
        int p_v = find_p(v);
        if(p_u == p_v) return;
        if(rank[p_u]>rank[p_v]){
            parent[p_v] = p_u;
        }
        else if(rank[p_v]>rank[p_u]){
            parent[p_u] = p_v;
        }
        else{
            parent[p_u] = p_v;
            rank[p_v]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        vector<int>result;
        for(auto j : edges){
            int u = j[0];
            int v = j[1];
            if(find_p(u)==find_p(v)){
                result.push_back(u);
                result.push_back(v);
                return result;
            }
            union_uv(u,v);
        }
        return result;
    }
};