class Solution {
public:
    string largestOddNumber(string num) {
        

        int n = num.size();
        int b = -1;
        for(int  i =0;i<n;i++){
            if((num[i] - '0')%2!=0){
                b=i;
            }
        }

        if(b==-1){
            return "" ;
        }
        else 

        return num.substr(0,b+1);


        
    }
};