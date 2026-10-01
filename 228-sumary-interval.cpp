class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<string> ans;
        for(int i=0; i<n; i++) {
            int r=nums[i], l=r;
            while(i+1<n && nums[i+1]==r+1) {
                r++;
                i++;
            }
            if(l==r)
                ans.push_back(to_string(l));
            else {
                ans.push_back(to_string(l)+"->"+to_string(r));
            }
        }
        return ans;
    }
};
