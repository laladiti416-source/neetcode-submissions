class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = *max_element(nums.begin(),nums.end());
        int curMin = 1;
        int curMax = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                curMin = 1;
                curMax = 1;
                continue;
            }
            int temp = curMin;
            curMin = min(min(curMin * nums[i],curMax * nums[i]),nums[i]);
            curMax = max(max(temp * nums[i],curMax * nums[i]),nums[i]);

            result = max(result,curMax);
        }
        return result;
    }
};
