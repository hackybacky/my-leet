class Solution {
public:
    int maxLength(vector<string>& arr) {
        int fans = 0;
        int n = arr.size();
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            
            int ans = 0;
            int seen = 0;
            for(int i = 0 ; i < ( n )  ; i++){
                int d  = (1<< i);
                if(d & mask){
                    string cur = arr[i];
                    for(auto it : cur){
                        int c = it - 'a';
                        if(seen & (1<< c)){
                            goto next;
                        }
                        seen |= (1<< c);
                    }
                    ans += cur.size();
                }
            }
            fans = max(fans , ans);
            
            next:;
        }
        return fans;
    }
};