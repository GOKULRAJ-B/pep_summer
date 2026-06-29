//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(auto i : nums){
            sum+=i;
            if(sum>maxSum) maxSum=sum;
            if(sum<0) sum = 0;
        }
        return maxSum;
    }
};