//https://leetcode.com/problems/k-closest-points-to-origin/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using P = pair<int, vector<int>>;
        priority_queue<P> maxHeap;

        for(auto i : points){
            int x = i[0];
            int y = i[1];
            int dis = x*x +  y*y;
            maxHeap.push({dis,{x,y}});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<vector<int>>result;
        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};