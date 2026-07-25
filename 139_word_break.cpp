class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        sort(words.begin(), words.end());
        int n=words.size(), ans=s.size();
        //vector<vector<bool>> aval(ans, vector<bool> (n, true));
        vector<bool> seen(ans+1, false);
        vector<int> pos(26, -1);
        for(int i=0; i<n; i++) {
            if(pos[words[i][0]-'a']==-1)
                pos[words[i][0]-'a']=i;
        }
        queue<int> next;
        next.push(0);
        while(!next.empty()) {
            int i=next.front();
            next.pop();
            if(i==ans)  return true;
            int v=pos[s[i]-'a'];
            if(v==-1 || seen[i])
                continue;
            seen[i]=true;
            for(int j=v; j<n && words[j][0]==s[i]; j++) {
                // if(!aval[i][j])
                //     continue;
                int k=0, sol=words[j].size();
                if(i+sol>ans)   continue;
                while(k<sol && i+k<ans && words[j][k]==s[i+k]) {
                    k++;
                }
                if(k==sol) {
                    next.push(i+k);
                    //aval[k+i].assign(aval[i].begin(), aval[i].end());
                    // aval[k+i]=aval[i]; //also giving error
                    // aval[i+k][j]=false;
                }
            }
        }
        return false;
    }
};
