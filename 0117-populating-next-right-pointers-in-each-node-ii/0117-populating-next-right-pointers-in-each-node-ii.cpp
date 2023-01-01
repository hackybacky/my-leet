/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            Node * prv = NULL;
            for(int i = 0 ; i < sz  ;i++){
                auto f = q.front();
                q.pop();
                if(i != 0)prv -> next = f;
                if(f -> left)q.push(f ->left);
                if(f -> right)q.push(f -> right);
                prv = f;
            }
            prv -> next = NULL;
        }
        return root;
    }
};