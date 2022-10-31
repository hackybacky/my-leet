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
class Solution {
public:
    class BSTIterator {
        public :
             bool reverse ;
             stack<TreeNode * > st;
        BSTIterator(TreeNode * root , bool isReverse){
            reverse = isReverse;
            push_node(root);
        }
        bool hasNext(){
            return !st.empty();
        }
        int next(){
            TreeNode * top = st.top();
            st.pop();
            if(reverse){
                push_node(top -> left);
            }
            else{
                push_node(top -> right);
            }
            return top -> val;
        }
        void push_node(TreeNode * root){
            while(root){
                st.push(root);
                if(reverse){
                    root = root -> right;
                }
                else root = root -> left;
            }
        }
        
    };
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root , false);
        BSTIterator right(root , true);
        vector<int>ans;
        int l = left.next() , r = right.next();
        while(l < r){
            int cur = l + r;
            if(cur < k){
                l = left.next();
            }
            else if(cur > k){
                r =right.next();
            }
            else{
                ans.push_back(l);
                cout << l << " " << r << endl;
                l = left.next();
                r = right.next();
                // return true;
            }
        }
        return ans.size() > 0;
    }
};