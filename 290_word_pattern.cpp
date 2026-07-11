class Solution {
public:
    bool wordPattern(string P, string S) {
        unordered_map<char, string> PS;
        unordered_map<string, char> SP;
        int j=0, i=0;
        for(; i<P.size(); i++) {
            if(j>=S.size()) return false;
            char p=P[i];
            int b=j;
            while(j<S.size() && S[j]!=' ') {
                j++;
            }
            string s=S.substr(b, j-b);
            j++;
            if((PS.contains(p) && PS[p]!=s) || (SP.contains(s) && SP[s]!=p))
                return false;
            PS[p]=s;
            SP[s]=p;
        }
        if(j<S.size())
            return false;
        return true;
    }
};
