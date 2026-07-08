class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1; i<strs.size(); i++) {
            string cmp= strs[i];
            int k=0;
            while(k<cmp.size() && k<ans.size() && cmp[k]==ans[k]) {
                k++;
            }
            ans.resize(k);
            if(k==0)
                break;
        }
        return ans;
    }
};
