//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    int maxReturn(vector<int>piles){
        int max = piles[0];
        for(int i=1;i<piles.size();i++){
            if(piles[i]>max) max=piles[i];
        }
        return max;
    }
    long long cal_hours(vector<int>piles,int h){
        long long totalHours = 0;
        for(int i=0; i<piles.size(); i++){
            totalHours += ceil(double(piles[i])/double(h));
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxReturn(piles);
        int k=INT_MAX;
        int ans;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            long long total_hours = cal_hours(piles,mid);
            if(total_hours<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;             
        }
        return ans;
    }
};