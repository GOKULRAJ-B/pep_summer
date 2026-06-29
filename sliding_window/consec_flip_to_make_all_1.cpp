//https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=problem-list-v2&envId=sliding-window
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = 2;
        while(j<nums.size()){
            if(nums[i]==1){
                i++;
                j++;
            }
            else{
                nums[i]=(nums[i]==1)?0:1;
                nums[i+1]=(nums[i+1]==1)?0:1;
                nums[i+2]=(nums[i+2]==1)?0:1;
                ans++;
                i++;
                j++;
            }
        }
        for(int k=0; k<nums.size(); k++){
            if(nums[k]==0) return -1;
        }
        return ans;
    }
};