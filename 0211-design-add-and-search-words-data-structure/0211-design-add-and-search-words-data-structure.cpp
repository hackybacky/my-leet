struct Node {
    Node *links[26];
    bool flag=false;
    bool containsKey(int l){
        return links[l]!=nullptr;
    }
    void addKey(int l ){
        links[l]=new Node();
    }
};
Node *root;
class Trie{
    public:
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node * node = root;
        for(auto it : word){
            int l = it-'a';
            if(node->containsKey(l)==false){
                node->addKey(l);
            }
            node=node->links[l];
        }
        node->flag=true;
    }
    bool search(string &word , Node * cur , int i){
    
        if(i==word.size()){
            // cout<<cur->flag<<endl;
           return cur->flag;
        }
        if(!cur)return false;
        bool ans=false;
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(cur->containsKey(j))
                ans|=search(word,cur->links[j],i+1);
            }
        }
        else{
            // cout<<word[i]<<endl;
            if(cur->containsKey(word[i]-'a'))
            ans =search(word,cur->links[word[i]-'a'],i+1);
        }
        return ans;
        
        
    }
};
class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        Node *node = root;
        return trie.search(word,node ,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */