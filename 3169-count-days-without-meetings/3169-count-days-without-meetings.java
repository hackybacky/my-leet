import java.util.*;


class Solution {
    
    public int countDays(int days, int[][] meetings) {
        int availableDays = 0;
        Arrays.sort(meetings , (a , b) -> Integer.compare(a[0] , b[0]));
        int maxBookDate = 0;
        for(int [] meeting : meetings){
            int startDate =  meeting[0];
            int endDate = meeting[1];
            
            
            availableDays += Math.max(0 ,startDate - maxBookDate - 1);
            maxBookDate = Math.max(maxBookDate , endDate);
        }
        return availableDays + days - maxBookDate;
    }
}