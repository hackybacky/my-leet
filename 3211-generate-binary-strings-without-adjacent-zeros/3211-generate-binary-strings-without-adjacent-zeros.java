class Solution {
    List<String>lans =  new ArrayList<>() ;
    public void recur(int i,char last,String ans){
        if(i == 0){lans.add(ans);return;}
        if(last == '0'){
            recur(i - 1 , '1', ans+"1");
        }
        else {
            recur(i - 1 , '0', ans +"0");
            recur(i - 1 , '1', ans + "1");
        }
        
    }
    public List<String> validStrings(int n) {
        recur(n,'a',"");
        return lans;
    }
}