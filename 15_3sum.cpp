class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ansset;
        //ansset.reserve(nums.size());
        sort(nums.begin(), nums.end());
        int S=nums.size()-1, i=0;
        while(i<S-1) {
            int l=i+1, r=S;
            while(l<r) {
                int sum= nums[l]+nums[i]+nums[r];
                if(sum==0) {
                    ansset.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if(sum<0)   l++;
                else r--;
            }
            i++;
        }
        vector<vector<int>> ans(ansset.begin(), ansset.end());
        return ans;
    }
};
