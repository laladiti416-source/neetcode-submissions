class Solution {
public:
    int dpSol(vector<int>& nums, int i, vector<vector<int>>& dp, bool pickedFirst)
    {
        int n = nums.size() - 1;
        
        // Base case: If we go out of bounds, or reach the last house having picked the first
        if(i > n || (i == n && pickedFirst))
        {
            return 0;
        }
        // Base case: Reached the last house and we DID NOT pick the first house
        if(i == n)
        {
            return nums[i];
        }
        
        // Convert boolean to 0 or 1 for indexing the DP table
        int state = pickedFirst ? 1 : 0;
        
        // Check cache for this specific index AND state
        if(dp[i][state] != -1)
        {
            return dp[i][state];
        }
        
        // Choice 1: Rob current house. Next index is i+2. 
        // If we are at index 0, pickedFirst becomes true.
        int robCurrent = nums[i] + dpSol(nums, i + 2, dp, pickedFirst || (i == 0));
        
        // Choice 2: Skip current house. Next index is i+1.
        int skipCurrent = dpSol(nums, i + 1, dp, pickedFirst);
        
        // Cache and return
        return dp[i][state] = max(robCurrent, skipCurrent);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // dp[n][2] -> rows represent index 'i', columns represent 'pickedFirst' (0 or 1)
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        // We start at index 0. Since we start at 0, pickedFirst starts as false, 
        // but it will immediately switch to true in the recursive step if we choose to rob it.
        return dpSol(nums, 0, dp, false);
    }
};