class Trie {
public:
    struct Node {
        Node * links[26];
        bool flag=false;
        bool containsKey(int l ){
            return links[l]!=NULL;
        }
        void addKey(int l ){
            links[l]=new Node();
        }
        bool isLeaf(){
            return flag;
        }
        void setLeaf(){
            flag=true;
        }
    };
    Node *root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(auto it : word){
            int l = it-'a';
            if(node->containsKey(l)==false){
                node->addKey(l);
            }
            node = node->links[l];
        }
        node->setLeaf();
    }
    
    bool search(string word) {
        Node *node =root;
        for(auto it : word){
            int l = it-'a';
            if(node->containsKey(l)==false){
                return false;
            }
            node = node->links[l];
        }
        
        return node->isLeaf();;
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(auto it : prefix){
            int l = it-'a';
            if(node->containsKey(l)==false)return false;
            node = node->links[l];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */