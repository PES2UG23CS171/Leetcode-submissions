class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0, l=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<l) {
                l=nums[i];
                continue;
            }
            ans+=nums[i]-l;
            l=nums[i];
        }
        return ans;
    }
};
