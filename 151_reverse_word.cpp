class Solution {
public:
    string reverseWords(string s) {
        string r="";
        r.reserve(s.size());
        int i=s.size()-1;
        while(i>=0 && s[i]==' ')
            i--;
        while(i>=0) {
            int j=i;
            while(j>=0 && s[j]!=' ')
                j--;
            r.append(s.substr(j+1, i-j));
            while(j>=0 && s[j]==' ')
                j--;
            if(j>=0)
                r.push_back(' ');
            i=j;
        }
        return r;
    }
};
