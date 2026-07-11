class Solution {
public:
    vector<int> size, parent;
    void create(int n) {
        size.assign(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i]=i;
    }
    int find(int a) {
        if(parent[a]!=a)
            parent[a]=find(parent[a]);
        return parent[a];
    }
    void _union(int a, int b) {
        int pa=find(a), pb=find(b);
        if(pa==pb)
            return;
        if(size[pa]<size[pb])
            swap(pa, pb);
        parent[pb]=pa;    
        size[pa]+=size[pb];
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        create(n);
        vector<int> seen(n, 0), hash(n,0);
        int ans=0;
        for(const auto& x: edges) {
            hash[x[0]]++;
            hash[x[1]]++;
            _union(x[0], x[1]);
        }
        for(int i=0; i<n; i++) {
            if(seen[parent[i]]==-1)
                continue;
            if(hash[i]==size[parent[i]]-1) {
                seen[parent[i]]++;
                if(seen[parent[i]]==size[parent[i]])
                    ans++;
            }
            else
                seen[parent[i]]=-1;
        }
        return ans;
    }
};
