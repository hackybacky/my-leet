class LRUCache {
public:
    class Node {
      public:
        int key;
        int val;
        Node * next;
        Node * prev;
        Node(int Key , int Val){
            key=Key;
            val=Val;
        }
    };
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    int c ;
    unordered_map<int , Node * >mp;
    LRUCache(int capacity) {
        c=capacity;
        head->next= tail;
        tail->prev=head;
    }
    void addNode(Node * newnode){
        auto nxt = head->next;
        newnode->next = nxt;
        nxt->prev=newnode;
        head->next=newnode;
        newnode->prev=head;
    }
    
    void deleteNode(Node *node){
        auto nxtnode = node ->next;
        auto prevnode = node->prev;
        prevnode->next=nxtnode;
        nxtnode->prev=prevnode;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            auto res = mp[key];
            int ans = res->val;
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        bool flag=false;
        if(mp.find(key)!=mp.end()){
            auto node = mp[key];
            // int val = node -> val;
           
            // deleteNode(node);
            deleteNode(node);
            node->val=value;
            mp.erase(key);
        }
        if(mp.size()==c){
            cout<<"helo"<<endl;
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        auto nw =new Node(key,value);
        addNode(nw);
        mp[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */