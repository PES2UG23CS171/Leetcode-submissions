class Solution {
public:
    vector<string> fullJustify(vector<string>& W, int maxW) {
        vector<string> ans;
        ans.reserve(W.size());
        int i=0, S=W.size();
        while(i<S) {
            string w;
            w.reserve(maxW);
            w.append(W[i]);
            int n=1, v=W[i].size();
            while(i+n<S && v+W[i+n].size()+n<=maxW) {
                v+=W[i+n].size();
                n++;
            }
            if(n==1) {
                w.append(string(maxW-v, ' '));
            }
            else if(n+i==S) {
                for(int j=1; j<n; j++)
                    w.append(' '+ W[j+i]);
                w.append(string(maxW-w.size(), ' '));
            }
            else {
                int b=(maxW-v)/(n-1), l=(maxW-v)%(n-1);
                for(int j=1; j<n; j++)
                    w.append(string(b + (j-1 < l ? 1 : 0), ' ') + W[i+j]);
            }
            ans.push_back(w);
            i+=n;
        }
        return ans;
    }
};
