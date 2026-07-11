class Solution {
public:
    bool isIsomorphic(string S, string T) {
        unordered_map<char, char> ST, TS;
        ST.reserve(128);
        TS.reserve(128);
        for(int i=0; i<S.size(); i++) {
            char s=S[i], t=T[i];
            if((ST.contains(s) && ST[s]!=t) || (TS.contains(t) && TS[t]!=s))
                return false;
            TS[t]=s;
            ST[s]=t;            
        }
        return true;
    }
};
