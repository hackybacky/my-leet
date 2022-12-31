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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        auto fast = head;
        for(int i = 0 ; i < n  ;i++)fast = fast -> next;
        auto slow = head;
        ListNode * pv = NULL;
        while(fast ){
            fast = fast -> next;
            pv = slow;
            slow = slow -> next;
        }
        if(slow == head)return slow -> next;
        pv -> next = slow -> next;
        return head;
    }
};