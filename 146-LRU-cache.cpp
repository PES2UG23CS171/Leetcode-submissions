class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int n;

    LRUCache(int capacity) {
        n=capacity;
        hash.reserve(n);
    }
    
    int get(int key) {
        if(!hash.contains(key))
            return -1;
        int v=(*hash[key]).second;
        if(hash[key]==prev(cache.end()))
            return v;
        cache.erase(hash[key]);
        cache.push_back({key, v});
        hash[key]=prev(cache.end());
        return v;
    }
    
    void put(int key, int value) {
        if(hash.contains(key)) {
            cache.erase(hash[key]);
            hash.erase(key);
        }
        cache.push_back({key, value});
        if(cache.size()>n) {
            hash.erase(cache.begin()->first);
            cache.pop_front();
        }
        hash[key]=prev(cache.end());
    }
};
