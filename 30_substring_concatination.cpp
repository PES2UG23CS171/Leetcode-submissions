class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //unordered_set<string> perm;
        unordered_map<string, int> legal;
        for(const auto& x: words)
            legal[x]++;
        vector<int> ans;
        int wsize=words.size(), w=words[0].size(), l=0;
        for(int i=0; i<w; i++) {
            multiset<string> win;
            for(int r=i; r<s.size(); r+=w) {
                string W=s.substr(r, w);
                if(!legal.contains(W)) {
                    win.clear();
                    continue;
                }
                if(win.empty())
                    l=r;
                win.insert(W);
                if(win.count(W)>legal[W]) {
                    string L= s.substr(l, w);
                    while(L!=W) {
                        win.erase(win.find(L));
                        l+=w;
                        L= s.substr(l, w);
                    }
                    win.erase(win.find(L));
                    l+=w;
                }
                while(win.size()>wsize) {
                    string L= s.substr(l, w);
                    win.erase(win.find(L));
                    l+=w;
                }
                if(win.size()==wsize) {
                    //string window= s.substr(l, r-l+1);
                    //if(!perm.contains(window)) {
                        ans.push_back(l);
                        //perm.insert(window);
                    //}
                }
            }
        }
        return ans;
    }
};
