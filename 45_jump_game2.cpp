class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int n=nums.size(), mx=nums[0], ans=1, i=0;
        while(mx<n-1) {
            int curmx=mx;
            ans++;
            while(i<=curmx) {
                mx=max(mx, i+nums[i]);
                i++;            
            }
        }
        return ans;
    }
};
