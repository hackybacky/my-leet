class MinStack {
public:
    class Node{
        public:
            int val ;
            int mn;
            Node * next;
            Node(int v , int m ,Node* n){
                val=v;
                mn=m;
                next=n;
            }
            
    };
    Node * head;
    MinStack() {
        head=new Node(INT_MAX,INT_MAX,nullptr);
        
    }
    
    void push(int v) {
        cout<<min(head->val,v)<<" "<<head->val<<endl;
        head = new Node(v,min(head->mn,v),head);
        
        
    }
    
    void pop() {
        head=head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */