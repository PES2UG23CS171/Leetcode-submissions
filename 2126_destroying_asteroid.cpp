class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) 
    {
        sort(ast.begin(), ast.end());
        long long m=mass;
        for(const auto& x: ast)
        {
            if(x> m)
                return false;
            m+=x;
        }
        return true;
    }
};
