//https://leetcode.com/problems/keys-and-rooms/?envType=problem-list-v2&envId=graph
class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<int> &state, int node){
        if(state[node]==1) return;
        state[node]=1;
        for(auto i : graph[node]){
            dfs(graph,state,i);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> state(rooms.size(),0);
        dfs(rooms,state,0);
        
        for(auto i : state){
            
            if(i==0) return false;
        }
        return true;
    }
};