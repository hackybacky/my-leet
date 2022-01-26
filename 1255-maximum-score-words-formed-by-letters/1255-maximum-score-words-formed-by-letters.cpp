class Solution {
public:
   
    int n;
    int ans;
    void solve(vector<string>&words,vector<int>&score,int i , map<char,int> &freq,int an){
        
        if(i==n){
            ans=max(ans,an);
            return ;
        }
        bool flag=true;
        map<char,int>cur;
        for(auto it : words[i]){
            cur[it]++;
        }
        for(auto it : words[i]){
            if(freq[it]<cur[it])flag=false;
        }
        
        if(!flag){
            solve(words,score,i+1,freq,an);
            
        }
        else{
            int t=0;
            for(auto it :words[i]){
                freq[it]--;
                t+=score[it-'a'];
            }
            solve(words,score,i+1,freq,an+t);
            
            for(auto it : words[i]){
                freq[it]++;
            }
            solve(words,score,i+1,freq,an);
            
        }
        
        
        
        
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