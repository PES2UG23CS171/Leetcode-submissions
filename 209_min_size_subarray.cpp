class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int ans=INT_MAX, l=0, sum=0;
        for(int r=0; r<nums.size(); r++) {
            sum+=nums[r];    
            while(sum>=t && l<=r) {
                ans=min(ans, r-l+1);
                sum-=nums[l++];
            }
        }
        return (ans==INT_MAX)? 0: ans;
    }
};
