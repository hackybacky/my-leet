class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int j =0;
        int n = s.size();
        for(int i=0;i<n ; i++ ){
            if(s[i]!=' '){
                if(j!=0)s[j++]=' ';
                int k = i;
                int start=j;
                while(k<n and s[k]!=' ')s[j++]=s[k++];
                reverse(s.begin()+start,s.begin()+j);
                i=k;
            }
        }
        s.erase(s.begin()+j,s.end());
        return s;
    }
};