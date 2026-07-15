class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int ans=0, l=0;
        for(int r=0; r<s.size(); r++) {
            if(hash.contains(s[r])) {
                l=max(l, hash[s[r]]+1);
            }
            hash[s[r]]=r;
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};
