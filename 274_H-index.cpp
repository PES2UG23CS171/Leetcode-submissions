class Solution {
public:
    int hIndex(vector<int>& nums) {
        int l=0, r=nums.size()+1;
        while(l<r) {
            int m=l+(r-l)/2, h=0;
            for(int i: nums) {
                if(i>=m)    h++;
            }
            if(h<m)
                r=m;
            else
                l=m+1;
        }
        return l-1;
    }
};
