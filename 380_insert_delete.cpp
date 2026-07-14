class RandomizedSet {
public:
    unordered_set<int> R;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool ans=R.contains(val);
        R.insert(val);
        return !ans;
    }
    
    bool remove(int val) {
        bool ans=R.contains(val);
        R.erase(val);
        return ans;
    }
    
    int getRandom() {
        int i = rand() % R.size();
        auto it = R.begin();
        advance(it, i);
        return *it;
    }
};
