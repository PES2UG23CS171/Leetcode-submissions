class Solution {
public:
    int minMutation(string S, string E, vector<string>& bank) 
    {
        set<string> valid(bank.begin(), bank.end());
        if(!valid.contains(E)) return -1;
        int ans=0;
        queue<string> next;
        next.push(S);
        while(!next.empty())
        {
            int qsize= next.size();
            ans++;
            while(qsize--)
            {
                string curr=next.front();
                next.pop();
                for(string s: valid)
                {
                    int x=0;
                    for(int i=0; i<8; i++)
                    {
                        if(s[i]!=curr[i])
                            x++;
                        if(x>1) break;
                    }
                    if(x==1)
                    {
                        valid.erase(s);
                        if(s==E)    return ans;
                        next.push(s);
                    }
                }
            }
        }
        return -1;
    }
};
