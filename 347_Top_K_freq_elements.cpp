class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int x) 
    {
        unordered_map<int, int> hash;
        for(int i: nums)
            hash[i]++;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>heap;
        for(const auto [k, v]: hash)
        {
            heap.push({v, k});
            if(heap.size()>x)
                heap.pop();
        }
        while(!heap.empty())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
