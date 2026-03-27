class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& P, vector<int>& C) 
    {
        vector<pair<int, int>> hash(P.size());
        for(int i=0; i<C.size(); i++)
            hash[i]= {C[i], P[i]};
        sort(hash.begin(), hash.end());
        priority_queue<int> next;
        int s=0;
        while(k--)
        {
            for(int i=s; i<hash.size() && hash[i].first<=w; i++)
            {
                next.push(hash[i].second);
                s=i+1;
            }
            if(next.empty())
                break;
            w+=next.top();
            next.pop();
        }
        return w;
    }
};
