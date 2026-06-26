
//https://leetcode.com/problems/sort-characters-by-frequency/?envType=problem-list-v2&envId=heap-priority-queue
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,long long>mpp;
        for(char c:s){
            mpp[c]++;
        }
        priority_queue<pair<long long,char>>maxHeap;
        for(auto i : mpp){
            maxHeap.push({i.second,i.first});
        }
        string str = "";
        long long count=0;
        while(!maxHeap.empty()){
            str.push_back(maxHeap.top().second);
            count++;
            if(count==maxHeap.top().first){
                count=0;
                maxHeap.pop();
            }
        }
        return str;
    }
};