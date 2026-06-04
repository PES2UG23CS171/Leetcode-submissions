class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int, int> hash;
        int S=arr.size(), t=arr.size()/2, ans=0;
        hash.reserve(S);
        hash.max_load_factor(0.25);
        for(int i:arr)
            hash[i]++;
        
        priority_queue<int> maxH;
        for(const auto& [x, y]: hash)
            maxH.push(y);
        while(S>t)
        {
            S-=maxH.top();
            ans++;
            maxH.pop();
        }
        return ans;
    }
};
