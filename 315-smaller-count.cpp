class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size(), mn=INT_MAX, mx=INT_MIN;
        for(int i: nums) {
            mn=min(mn, i);
            mx=max(mx, i);
        }
        int sz=mx-mn+2;
        vector<int> ans(n, 0), tree(sz, 0);
        for(int i=n-1; i>=0; i--) {
            int val=nums[i]-mn, sum=0, j=val;
            while(j>0) {
                sum+=tree[j];
                j-=j&-j;
            }
            j=val+1;
            ans[i]=sum;
            while(j<sz) {
                tree[j]++;
                j+=j&-j;
            }
        }
        return ans;
    }
};
