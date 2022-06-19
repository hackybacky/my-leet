class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(),products.end());
        
        
        string cur ="";
        vector<vector<string>>lans;
        auto last=products.begin();
        int len=0;
        for(auto it2 : searchWord){
            cur+=it2;
            len++;
            auto it = lower_bound(last,products.end(),cur);
            last=it;
            vector<string>v;
            for(int i=0;i<3 and it!=products.end();it++,i++){
                if((*it).substr(0,len)==cur)
                v.push_back(*it);
            }
            lans.push_back(v);
        }
        return lans;
    }
};