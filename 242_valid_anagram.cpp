class Solution {
public:
    bool isAnagram(string S, string T) {
        if(S.size()!=T.size())  return false;
        unordered_map<char, int> hash;
        hash.reserve(128);
        for(int i=0; i<S.size(); i++) {
            hash[S[i]]++;
            hash[T[i]]--;
        }
        for(auto [c, v]: hash) {
            if(v != 0)
                return false;
        }
        return true;
    }
};
