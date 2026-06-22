class Solution {
public:
    int rearrangeCharacters(string s, string tar) {
        vector<int> T(26, 0), S(26, 0);
        for(char c: s)  S[c-'a']++;
        for(char c: tar) T[c-'a']++;
        int c=INT_MAX;
        for(int i=0; i<26; i++)
        {
            if(T[i]!=0 && c>(S[i]/T[i]))
                c=S[i]/T[i];
        }
        return c;
    }
};
