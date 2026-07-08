class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            while(!Q.empty() && nums[Q.back()]<nums[i])
                Q.pop_back();
            while(!Q.empty() && Q.front()<=i-k)
                Q.pop_front();
            Q.push_back(i);
            if(i>=k-1)   
                ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            win.insert(nums[i]);
            if(win.size()>k) 
                win.erase(win.find(nums[i-k]));
            if(win.size()==k)
                ans.push_back(*win.rbegin());
        }
        return ans;
    }
};
*/
