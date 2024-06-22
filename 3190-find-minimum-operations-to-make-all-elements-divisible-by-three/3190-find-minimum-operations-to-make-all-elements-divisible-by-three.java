class Solution {
    public int minimumOperations(int[] nums) {
        int sum = 0;
        for (int i : nums){
            if(i % 3 != 0){
                sum ++;
            }
        }
        return sum;
    }
}