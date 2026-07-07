class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n=nums.size(), ans=n;
        sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int m=nums[0][1];
        for(int i=1; i<n; i++) {
            if(nums[i][1]<=m)
                ans--;
            else
                m=nums[i][1];
            
        }
        return ans;
    }
};
