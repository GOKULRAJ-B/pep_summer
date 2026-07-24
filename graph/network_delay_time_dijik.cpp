//https://leetcode.com/problems/network-delay-time/?envType=problem-list-v2&envId=graph
class Solution {

public:

    void find_dist(vector<vector<int>> &times, vector<int> &dist, int src, int n){
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &j : times){
            adj[j[0]].push_back({j[1],j[2]});
        }
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto &j : adj[node]){
                int adjnode = j.first;
                int wt = j.second;
                if(wt+dis<dist[adjnode]){
                    dist[adjnode] = wt+dis;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        find_dist(times,dist,k,n);
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};