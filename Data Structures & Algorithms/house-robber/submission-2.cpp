class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+2,-1);
        int prev = nums[n];
        int curr = INT_MIN;
        int prev2 = 0;
        for(int i=n-1;i>=0;i--)
        {
            curr = max((nums[i] + prev2), prev);
            prev2 = prev;
            prev = curr;


        }
        return prev;
    }
};
