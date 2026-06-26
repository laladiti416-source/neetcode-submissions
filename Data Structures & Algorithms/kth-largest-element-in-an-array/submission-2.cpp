class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        if(nums.size() == 1)
        {
            return nums[0];
        }
        for(auto num: nums)
        {
            pq.push(num);
        }

        while(--k)
        {
            pq.pop();
        }
        return pq.top();

    }
};
