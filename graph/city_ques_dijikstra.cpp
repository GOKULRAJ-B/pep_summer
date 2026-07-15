//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=problem-list-v2&envId=graph
class Solution {
public:
    void dist_find(vector<vector<pair<int,int>>> &adj, vector<int>&dist, int src, int &count, int t){
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;
        minHeap.push({0,src});
        dist[src]=0;
        while(!minHeap.empty()){
            int weight = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            if(weight > dist[node]) continue;
            for(auto &i : adj[node]){
                int wt = i.second; 
                int u = i.first;
                if(wt+weight<dist[u]){
                    dist[u] = wt+weight;
                    minHeap.push({dist[u],u});
                } 
            }
        }
        for(int d : dist){
            if(d <= t) count++;
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int minCount = INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++){
            vector<int>dist(n,1e9);
            int count = 0;
            dist_find(adj,dist,i,count,distanceThreshold);
            if(count<minCount){
                index = i;
                minCount = count;
            }
            else if(count==minCount){
                index = max(index,i);
            }
        }
        return index;
        
        
    }
};