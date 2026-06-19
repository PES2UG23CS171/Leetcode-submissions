class Solution {
public:
    void right(vector<int>& nums, int l, int r)
    {
        while(l<r)
        {
            int t=nums[l];
            nums[l++]=nums[r];
            nums[r--]=t;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        reverse(nums.begin(), nums.end());
        right(nums, 0, k-1);
        right(nums, k, nums.size()-1);
    }
};
