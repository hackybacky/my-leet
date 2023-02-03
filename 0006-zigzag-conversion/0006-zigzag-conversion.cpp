class Solution {
public:
    string convert(string s, int numRows) {
        
        int n =s.size();
        if(n==1 or numRows==1)return s;
        int j=0;
        vector<string > ans(numRows,"");
        for(int i=0;i<n;i++){
            while(j<numRows and i<n )ans[j]+=s[i],j++,i++;
            j-=2;
            while(j>=1 and i<n)ans[j]+=s[i],i++,j--;
            i--;
        }
        string lans="";
        for(int  i=0;i<numRows;i++){
            if(ans[i].size()>0)lans+=ans[i];
            
        }
        return lans;
        
    }
};