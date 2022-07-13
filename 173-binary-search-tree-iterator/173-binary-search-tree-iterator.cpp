/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode * > st;
    TreeNode * cur;
    BSTIterator(TreeNode* root) {
        travel(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();
        travel(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void travel(TreeNode*root){
        while(root)st.push(root),root=root->left;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */