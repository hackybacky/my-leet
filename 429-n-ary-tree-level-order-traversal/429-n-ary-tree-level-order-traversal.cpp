/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if( !root) return {};
        queue<Node * > q;
        q.push(root);
        vector<vector<int>>ans;
        while( !q.empty()){
            int sz = q.size() ;
            vector<int>cur;
            for(int i = 0 ; i < sz ; i++){
                Node * c = q.front();
                cur.push_back(c->val);
                q.pop();
                for( auto it : c->children ){
                    q.push(it);
                }
            }
            ans.push_back(cur);
        }
        return ans; 
    }
};