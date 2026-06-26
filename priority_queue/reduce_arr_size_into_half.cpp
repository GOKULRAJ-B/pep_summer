//https://leetcode.com/problems/reduce-array-size-to-the-half/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        int half_size = arr.size()/2;
        unordered_map<int,int>mpp;
        priority_queue<int> maxHeap;

        for(auto i : arr){
            mpp[i]++;
        }

        for(auto i : mpp){
            maxHeap.push(i.second);
        }

        int reduced = 0;
        int ans = 0;

        while(!maxHeap.empty()){
            reduced += maxHeap.top();
            maxHeap.pop();
            ans++;
            if(reduced>=half_size){
                break;
            }
        }
        return ans;
    }
};