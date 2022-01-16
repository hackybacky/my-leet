class Solution {
public:
    int n,m;
    int pills, strengt;
    bool check(int mid ,vector<int> &workers ,vector<int>&tasks){
            
            if(mid>m)return false;
            multiset<int> s(workers.end()-mid,workers.end());
            
            // if(mid==3)for(auto it : s)cout<<it<< " ";
            // cout<<endl;
            
            for(int i=mid-1 ; i>=0 ; i--){
                
                int x=tasks[i];
                auto it =s.lower_bound(x);
                if(it==s.end()){
                    if(pills==0){
                        
                        return false;
                    }
                    //cout<<mid<<endl;
                    int y= x-strengt;
                    auto it2= s.lower_bound(y);
                    
                    if(it2==s.end()){return false;}
                    else s.erase(it2);
                    pills--;
                    
                }
                else{
                    
                    s.erase(it);
                }
            }
            return true;
        }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int dp, int strength) {
     n=tasks.size();
         strengt=strength;
         m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        
        int d=20;
        int l=0,r=min(n,m);
        while(l<=r){
            pills=dp;
            int mid=(l+r)/2;
            if(check(mid,workers,tasks)){
                l=mid+1;
                
            }
            else r=mid-1;
            
        }
        return l-1;
    }
};