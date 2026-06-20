class Solution {
public:
    string convert(string s, int n) 
    {
        if(n==1)    return s;
        vector<string> part(n, "");
        int i=0, p=0;
        bool dir=true;
        while(i<s.size())
        {
            part[p]+=s[i++];
            if(p==0)    dir=true;
            else if(p==n-1) dir=false;
            if(dir) p++;
            else    p--;
        }
        string ans="";
        for(string p: part)
            ans+=p;
        return ans;
    }
};
