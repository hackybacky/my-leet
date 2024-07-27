class Solution {
    public int maxOperations(String s) {
        
        int n = s.length();
        boolean flag = false;
        int cur = 0;
        int ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s.charAt(i) == '0'){
                if(!flag)cur++;
                flag = true;
            }
            else{
                ans += cur;
                flag = false;
            }
        }
        return ans;
    }
}