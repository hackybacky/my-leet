class Solution {
public:
    struct Node{
        Node * links[26];
        bool containsKey(char c ){
            return links[c - 'a'] != NULL;
        }
        
        int cnt = 0;
        void increaseCnt(){
            cnt++;
        }
        
    };
    class Trie{
        public:
        Node * root;
            Trie(){
                root = new Node();
            }
        void insert(string & word){
            Node * node = root;
            for(auto it : word){
                if(node->containsKey(it) == false){
                    node -> links[it - 'a'] = new Node();
                }
                node = node -> links[it - 'a'];
                node -> increaseCnt();
            }
        }
        int search(string & word){
            Node * node = root;
            int ans = 0;
            for(auto it : word){
                node = node -> links[it - 'a'];
                ans += node -> cnt;
            }
            return ans;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto it : words){
            trie.insert(it);
            
        }
        vector<int>ans;
        for(auto it : words){
            ans.push_back(trie.search(it));
        }
        return ans;
    }
};