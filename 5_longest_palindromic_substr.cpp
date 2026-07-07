class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0; i<n; i++) {
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]) { 
                l--;
                r++;
            }
            //loop breaks after incrementing from valid case so we reverse it
            if(r-l-1>ans.size())
                ans=s.substr(l+1, r-l-1);
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) { 
                l--;
                r++;
            }
            if(r-l-1>ans.size())
                ans=s.substr(l+1, r-l-1);
        }
        return ans;
    }
};
