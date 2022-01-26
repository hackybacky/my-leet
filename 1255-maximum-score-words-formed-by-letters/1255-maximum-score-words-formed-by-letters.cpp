class Solution {
public:
   
    int n;
    int ans;
    void solve(vector<string>&words,vector<int>&score,int i , map<char,int> &freq,int an){
        
        if(i==n){
            ans=max(ans,an);
            return ;
        }
        
            int t=0;
            bool flag=false;
            for(auto it :words[i]){
                freq[it]--;
                t+=score[it-'a'];
                if(freq[it]<0)flag=true;
            }
            if(!flag)
            solve(words,score,i+1,freq,an+t);
            
            for(auto it : words[i]){
                freq[it]++;
            }
            solve(words,score,i+1,freq,an);
            
        
        
        
        
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        map<char,int>freq;
        for(auto it :letters){
            freq[it]++;
        }
        
        solve(words,score,0,freq,0);
        return ans;
        
    }
};