class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int anssize=INT_MAX, l=0, tsize=t.size(), cond=0;
        int hash[128]={0}, win[128]={0};
        for(char c: t) {
            hash[c]++;
        }
        for(int r=0; r<s.size(); r++) {
            char c=s[r];
            if(hash[c]) {   //hash[c]>0
                if(win[c]<hash[c])
                    cond++;
                win[c]++;
            }
            while(l<=r && (!hash[s[l]] || hash[s[l]]<win[s[l]])) {
                if(win[s[l]])
                    win[s[l]]--;
                l++;
            }
            if(cond==tsize && anssize>r-l+1) {
                anssize=r-l+1;
                ans=s.substr(l, anssize);                
            }
        }
        return ans;
    }
};
