class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int s=nums.size(), ans=0;
        vector<int> pref(s+1, 0);
        for(int i=0; i<s; i++) {
            if(nums[i]==t)
                pref[i+1]=pref[i]+1;
            else
                pref[i+1]=pref[i]-1;
        }
        for(int r=0; r<s; r++) {
            for(int l=0; l<=r; l++) {
                int sum=pref[r+1]-pref[l];
                if(sum>0)   ans++;
            }
        }
        return ans;
    }
};
