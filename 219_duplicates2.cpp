class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash.reserve(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if(hash.contains(nums[i]) && i-hash[nums[i]]<=k)
                return true;
            hash[nums[i]]=i; 
        }
        return false;
    }
};
