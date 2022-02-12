class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string > q;
        
        q.push(beginWord);
        int ans=0;
        int m=endWord.size();
    
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        map<string,int> dist;
        int maxi=1e9;
        bool flag=false;
        while(!q.empty()){
           string t = q.front();
            q.pop();
            if(t==endWord){
                flag=true;
                maxi = min(dist[t],maxi);
            }
            for(int i=0 ; i< m ; i++){
                string c=t;
                for(int j=0; j<26; j++){
                    c[i]='a'+j;
                    if( st.find(c)!=st.end() and c!=t){
                        q.push(c);
                        dist[c]=dist[t]+1;
                        st.erase(c);
                    }
                }
            }
            
        }
       // for(auto it : dist)cout<<it.first<<" "<<it.second<<endl;
        if(!flag)return 0;
        return maxi+1;
    }
};