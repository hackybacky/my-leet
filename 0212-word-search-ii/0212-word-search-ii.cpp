class Solution {
public:
     
    
    struct node{
        node * links[26];
        bool contains(char c){
            return links[c  - 'a'] != NULL;
        }
        
        bool isEnd = false;
        void setEnd(){
            isEnd = true;
        }
    };
    class Trie{
        public :
            node * root ;
            Trie(){
                root = new node();
            }
            set<string>ans;
            vector<int> x = {1, -1, 0, 0};
             vector<int> y = {0, 0, 1, -1};
            void insert(string & word){
                node * curn = root;
                for(auto it : word){
                    if(curn -> contains(it) == false){
                        curn -> links[it - 'a'] = new node();
                    }
                    curn = curn -> links[it - 'a'];
                }
                curn -> setEnd();
            }
            void search(vector<vector<char >> &board , int curx , int cury , string& cur  , node * no ){
                
                if(curx < 0 or cury < 0 or curx >= board.size() or cury >= board[0].size() or board[curx][cury] == 'V')return ;
                char c = board[curx][cury];
                if(no -> contains(c) == false){
                    return ;
                }
                no = no -> links[c - 'a'];
                cur += c;
                if(no -> isEnd){
                    ans.insert(cur);
                    no -> isEnd = false;
                }
                board[curx][cury] = 'V';
                for(int k = 0 ; k < 4 ; k++){
                    int nx = curx + x[k];
                    int ny = cury + y[k];
                    search(board , nx , ny , cur  , no);
                }
                cur.pop_back();
                board[curx][cury] = c;
                
            }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        Trie trie;
        for(auto it : words){
            trie.insert(it);
        }
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                string cur = "";
                trie.search(board , i , j , cur , trie.root);
            }
        }
        vector<string>a(trie.ans.begin() , trie.ans.end());
        return a;
    }
};