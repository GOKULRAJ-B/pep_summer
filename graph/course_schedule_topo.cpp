//https://leetcode.com/problems/course-schedule-ii/?envType=problem-list-v2&envId=graph
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for( int j : adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(result.size()==numCourses) return result;
        else{
            vector<int>r;
            return r;
        }
    }

};