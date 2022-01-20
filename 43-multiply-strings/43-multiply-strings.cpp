class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0")return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int>ans(m*n+1,0);
        
        
        for(int i=m-1 ; i>=0 ; i--){
            int prevcarry=0;
            int j;
            for( j=n-1 ; j>=0  ; j--){
                int a=num2[i]-'0';
                int b=num1[j]-'0';
                
                int c=b*a+prevcarry;
                
                int newcarry=c/10;
                
                int cur=c%10;
                cout<<cur<<endl;
                ans[n-1-j+m-1-i]+=cur;
                prevcarry=newcarry;
            }
            if(prevcarry){
                ans[n-1-j+m-1-i]=prevcarry;
            }
        }
        string sans="";
        int carry=0;
        
        for(int i=0 ; i<n*m+1 ; i++){
                char c=((ans[i]+carry)%10+'0');
                sans= c+sans;
                carry=(ans[i]+carry)/10;
            
        }
        
        if(carry){
            char c=(carry+'0');
            sans=c+sans;
        }
        string an="";
        cout<<sans<<endl;
        int i=0;
        while(i<sans.size() and sans[i]=='0')i++;
        while(i<sans.size()){
            an+=sans[i];
            i++;
        }
     
        return an;
            
        
        
        
    }
};