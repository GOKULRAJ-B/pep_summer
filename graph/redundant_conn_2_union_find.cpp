//https://leetcode.com/problems/redundant-connection-ii/?envType=problem-list-v2&envId=graph
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<n+1;i++){
            parent[i] = i;
        }
        vector<int>indegree(n+1,0);
        for(auto j : edges){
            indegree[j[1]]++;
        }
        vector<int>e1;
        vector<int>e2;
        bool two_degree = false;
        for(auto &j : edges){
            if(indegree[j[1]]>1){
                if(e1.size()==0){
                    two_degree = true;
                    e1=j;
                }
                else{
                    e2=j;
                }
            }
        }
        for(auto &j : edges){
            if(two_degree){
                if(j==e2) continue;
                if(find_p(j[0]) == find_p(j[1])){
                    return e1;
                }
                union_uv(j[0],j[1]);
            }
            else{
                if(find_p(j[0]) == find_p(j[1])){
                    return j;
                }
                union_uv(j[0],j[1]);
            }
        }
        return e2;
    }
};