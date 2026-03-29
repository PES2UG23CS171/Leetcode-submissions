class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int, int > hash;
        for(const auto& i: arr)
            hash[i]++;
        vector<int> heap;
        for(auto [key, v]: hash)
            heap.push_back(v);
        sort(heap.begin(), heap.end());
        for(int i=0; i<heap.size(); i++)
        {
            if(heap[i]>k)
                return heap.size()-i;
            k-=heap[i];
        }
        return 0;
    }
};
