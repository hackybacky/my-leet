class WordFilter {
public:
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
    unordered_map<pair<string,string>,int,hash_pair> mp;
    
    WordFilter(vector<string>& words) {
        int k=0;
        for(auto it : words){
            auto cur = it;
            int sz = cur.size();
            for(int i=0;i<=sz ; i++){
                string p = cur.substr(0,i);
                for(int j=0 ; j<sz ; j++){
                    auto s = cur.substr(j);
                    mp[{p,s}]=k;
                }
            }
            k++;
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp.find({prefix,suffix})==mp.end())return -1;
        return mp[{prefix,suffix}];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */