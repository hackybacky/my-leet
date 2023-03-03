class Solution {
public:
    const int mod = 1e9+7;
    int kmp(string &a , string &b){
        int p=29;
        int lena = a.size();
        int  lenb = b.size();
        vector<long long>pow(max(lena,lenb),0);
        pow[0]=1;
        for(int i=1;i<max(lena,lenb);i++){
            pow[i]=(pow[i-1]*p)%mod;
        }
        vector<long long int>hash(lena+3,0);
        for(int i=0;i<lena ; i++){
            hash[i+1]= (hash[i]+((a[i]-'a'+1)*pow[i])%mod)%mod;
        }
        long long ncur=0;
        for(int i=0;i<lenb ; i++){
            ncur=(ncur+((b[i]-'a'+1)*pow[i])%mod)%mod;
        }
        // for(auto it:hash)cout<<it<<" ";
        // cout<<ncur<<endl;
        for(int i=0;i<=lena-lenb ; i++){
            long long int cur = (hash[i+lenb]-hash[i]+mod)%mod;
            // cout<<cur<<endl;
            if((ncur*pow[i])%mod==cur)return i;
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return kmp(haystack , needle);
    }
};