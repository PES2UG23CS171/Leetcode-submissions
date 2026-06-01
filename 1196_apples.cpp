class Solution {
public:
    int maxNumberOfApples(vector<int>& B) {
        int w=5000, i=0;
        sort(B.begin(), B.end());
        for(; i<B.size() && B[i]<=w; i++)
            w-=B[i];
        return i;
    }
};
