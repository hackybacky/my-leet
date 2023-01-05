/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        return to_string(root -> val) + ","+ serialize(root -> left ) + ","+ serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream st(data);
        return deserial(st );
    }
    TreeNode * deserial(stringstream &st){
        string cur ;
        getline(st , cur , ',');
        if(cur == "#")return NULL;
        int val = stoi(cur);
        TreeNode * node = new TreeNode(val);
        node -> left = deserial(st);
        node -> right = deserial(st);
        return node;
        cout << cur << endl;
        return NULL;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));