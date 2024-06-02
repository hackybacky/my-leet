class Solution {
    public int minimumChairs(String s) {
        
        int minChair = Integer.MIN_VALUE;
        int currentRequiredChair = 0;
        for(int i = 0 ; i < s.length() ; i++){
            char c = s.charAt(i);
            if( c == 'E'){
                currentRequiredChair += 1;
            }
            else currentRequiredChair -= 1;
            minChair = Math.max(minChair , currentRequiredChair);
        }
        return minChair;
    }
}