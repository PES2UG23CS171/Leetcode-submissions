class Solution {
public:
    int kadane(vector<int>& nums, int s) {
        int n=nums.size(), curr=nums[s], ans=nums[s];
        for(int i=1; i<n; i++) {
            int in= (s+i+n)%n;
            curr=max(curr+nums[in], nums[in]);
            ans=max(curr, ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=nums[0];
        for(int i=0; i<8; i++)
            ans=max(ans, kadane(nums, nums.size()*0.125*i));
        return ans;
    }
};
