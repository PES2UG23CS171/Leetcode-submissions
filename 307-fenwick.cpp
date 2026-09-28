class NumArray {
private:
    vector<int> og, tree;
    int calc(int i) {
        int sum=0;
        while(i>0) {
            sum+=tree[i];
            i-=i&-i;
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        og=nums;
        tree.push_back(0);
        tree.insert(tree.end(), nums.begin(), nums.end());
        int n=tree.size();
        for(int i=1; i<n; i++) {
            int p=i+(i&-i);
            if(p<n) {
                tree[p]+=tree[i];
            }
        }
    }
    
    void update(int i, int val) {
        int diff=val-og[i];
        og[i]=val;
        i++;
        while(i<tree.size()) {
            tree[i]+=diff;
            i+=i&-i;
        }
    }
    
    int sumRange(int left, int right) {
        return calc(right+1)-calc(left);
    }
};
