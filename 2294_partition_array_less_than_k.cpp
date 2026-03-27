class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int ans=1, l=nums[0];
        for(const auto& x: nums)
        {
            if(x-l>k)
            {
                l=x;
                ans++;
            }
        }
        return ans;
    }
};
