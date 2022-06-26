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
     void insert(int n){
        Node * node=root;
        for(int i=30;i>=0;i--){
           
            int cur = (n>>i)&1;  
            
            // cout<<cur<<endl;
            if(node->containsKey(cur)==false){
                 // if(cur==1)cout<<"kj"<<endl;
                node->addKey(cur);
                
            }
            node=node->links[cur];
    
        }
    }
    int giveans(int n){
        Node * node= root;
        int ans=0;
        for(int i=30;i>=0;i--){
            int d =(1<<i)&n;
            if(d)d=1;
            int cur = d^1;
           
            if( node->containsKey(cur)){
                ans+=(1<<i);
                node=node->links[cur];
            }
            else{
                node=node->links[d];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it : nums){
            trie.insert(it);
        }
        int ans=0;
        for(auto it : nums){
            ans=max(ans,trie.giveans(it));
        }
        return ans;
    }
};