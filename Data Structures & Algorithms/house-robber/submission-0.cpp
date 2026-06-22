class Solution {
public:
    int dpSol(vector<int>& nums, int i,vector<int>& dp)
    {
        int n = nums.size()-1;
        if(i > n)
        {
            return 0;
        }
        if(i == n)
        {
            return nums[i];
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
       return dp[i] =  max((nums[i] + dpSol(nums,i+2,dp)), dpSol(nums,i+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return dpSol(nums,0,dp);
    }
};
