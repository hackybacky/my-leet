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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int curk =0;
        auto node = head;
        while(curk<k-1){
            node = node ->next;
            curk++;
        }
        auto kstart = node;
        
        auto dnode = head;
        
        while( node->next ){
            node =node ->next;
            dnode = dnode ->next;
        }
        
        swap(dnode->val,kstart->val);
        return head;
        
    }
};