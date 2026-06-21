class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, e=0;
        for(int i:nums)
        {
            // boyer-moore
            if(count==0)  e=i;
            if(e==i)    count++;
            else    count--;
        }
        return e;
        //sort(nums.begin(), nums.end());
        //return nums[nums.size()/2];
    }
};
