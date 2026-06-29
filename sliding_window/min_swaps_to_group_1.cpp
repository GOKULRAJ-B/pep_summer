//https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int occ=0;
        for(auto i : nums){
            if(i==1) occ++;
        }
        int currOcc=0;
        for(int i=0;i<occ;i++){
            currOcc+=nums[i];
        }
        int maxOcc = currOcc;
        int n = nums.size();
        for(int i=occ; i<=n+occ;i++){
            currOcc+=nums[i%n];
            currOcc-=nums[(i-occ)%n];
            maxOcc=max(maxOcc,currOcc);
        }
        return occ-maxOcc;
    }
};