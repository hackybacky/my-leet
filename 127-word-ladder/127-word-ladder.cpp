class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string > q;
        
        q.push(beginWord);
        int ans=0;
        int m=endWord.size();
    
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty()){
            int n=q.size();
           for(int i=0;i<n;i++){
                string s =q.front();
            q.pop();
            if(s==endWord)return ans+1;
            st.erase(s);
            for(int i=0; i< m ; i++){
                string c=s;
                for(int j=0; j<26 ; j++){
                    c[i]='a'+j;
                    auto it =st.find(c);
                    if(it!=st.end() ){
                       q.push(c);
                        //cout<<c<<endl;
                        
                    }
                }
                
            }
           }
            ans++;
            
        }
        return 0;
    }
};