class Solution {
public:
    int maxArea(vector<int>& H) {
        int l=0, r=H.size()-1, ans=0;
        while(l<r) {
            if(H[l]<=H[r]) {
                ans= max(ans, H[l]*(r-l));
                l++;
            }
            else {
                ans= max(ans, H[r]*(r-l));
                r--;
            }
        }
        return ans;
    }
};
