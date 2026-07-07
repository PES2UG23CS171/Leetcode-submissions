class Solution {
public:
    int longestCommonSubsequence(string S1, string S2) {
        vector<int> prev(S1.size()+1, 0), curr(S1.size()+1, 0);
        for(char c: S2) {
            for(int i=0; i<S1.size(); i++) {
                if(S1[i]==c)
                    curr[i+1]=prev[i]+1;
                else
                    curr[i+1]=max(prev[i+1], curr[i]);
            }
            swap(curr, prev);
        }
        return prev.back();
    }
};
