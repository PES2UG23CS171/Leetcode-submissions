class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> heap(nums.begin(), nums.end());
        int ans;
        for(int i=0; i<k; i++)
        {
            ans=heap.top();
            heap.pop();
        }
        return ans;
    }
};
