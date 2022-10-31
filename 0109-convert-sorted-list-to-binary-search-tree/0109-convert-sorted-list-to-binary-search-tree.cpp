/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode * recur(ListNode * head , ListNode * tail){
        if(tail == NULL){
            return NULL;
        }
        if(!head ){
            return NULL;
        }
        if(head == tail){
            return new TreeNode(tail -> val);
        }
        
        auto fast = head -> next;
        auto slow = head;
        ListNode * p = NULL;
        while(fast != tail and fast != tail -> next){
            fast = fast -> next -> next;
            p = slow;
            slow = slow -> next;
        }
        
        TreeNode * root = new TreeNode(slow -> val);
        // cout << root -> val << endl;
        root -> left = recur(head , p );
        root -> right = recur(slow -> next ,tail);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        auto tail = head;
        while(tail -> next){
            tail = tail -> next;
        }
        return recur(head , tail);
    }
};