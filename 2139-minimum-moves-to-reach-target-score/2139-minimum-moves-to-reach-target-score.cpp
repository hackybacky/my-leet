class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(maxDoubles and target>1){
            if(target%2==0)target/=2,maxDoubles--;
            else target--;
            ans++;
        }
        
        return ans+target-1;
    }
};