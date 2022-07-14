class Solution {
public:
    bool prefix_function(string s,int lena) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }   
        for(auto it : pi)cout<<it<<" ";
        return find(pi.begin(),pi.end(),lena)!=pi.end();
    }
    int repeatedStringMatch(string a, string b) {
        
        string ans="";
        int cnt=0;
        int lena = a.size();
        int cur =0;
        int lenb=b.size();
        while(cur<lenb){
            cur+=lena;
            cnt++;
            ans+=a;
        }
        // cout<<ans<<endl;
        if(ans==b or prefix_function(b+"#"+ans,lenb) )return cnt;
        else {
            string d = ans+a;
            cout<<d<<endl;
            if(prefix_function(b+"#"+d,lenb))return cnt+1;
        }
        return -1;
    }
};