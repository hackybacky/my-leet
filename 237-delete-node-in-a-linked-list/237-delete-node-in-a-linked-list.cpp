/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode * prev = NULL;
        
        while(node->next){
            
            int v = node->next->val;
            node->val=v;
            prev=node;
            node=node->next;
        }
        prev->next = NULL;
        
    }
};