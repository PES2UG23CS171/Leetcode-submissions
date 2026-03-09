class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        string L=(text1.size() > text2.size())? text1: text2;
        string S=(L==text1)? text2: text1;
        vector<int> prev(S.size()+1, 0);
        for(int i=0; i<L.size(); i++)
        {
            vector<int> curr(S.size()+1, 0);
            for(int j=0; j < S.size(); j++)
            {
                if(L[i]==S[j])
                    curr[j+1]=prev[j]+1;
                else
                    curr[j+1]=max(prev[j+1], curr[j]);
            }
            prev=curr;
        }
        return prev.back();        
    }
};
