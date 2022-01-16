class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        auto check=[&](int mid){
            if(mid>m)return false;
            multiset<int> s;
            for(int i=0 ; i< mid ; i++){
                s.insert(workers[m-1-i]);
            }
            // if(mid==3)for(auto it : s)cout<<it<< " ";
            // cout<<endl;
            
            for(int i=mid-1 ; i>=0 ; i--){
                int x=tasks[i];
                
                if(x>(*s.rbegin())){
                    if(!pills){
                        
                        return false;
                    }
                    //cout<<mid<<endl;
                    int y= x-strength;
                    auto it2= s.lower_bound(y);
                    
                    if(it2==s.end()){return false;}
                    else s.erase(it2);
                    pills--;
                    
                }
                else{
                    auto it =s.lower_bound(x);
                    s.erase(it);
                }
            }
            return true;
        };
        int dp=pills;
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                l=mid+1;
                
            }
            else r=mid-1;
            pills=dp;
        }
        return l-1;
    }
};