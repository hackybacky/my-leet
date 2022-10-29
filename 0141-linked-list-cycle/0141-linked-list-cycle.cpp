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
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        if(head -> next == head){
            return true;
        }
        ListNode * slow = head;
        ListNode * fast = head -> next;
        while(fast and fast -> next and fast != slow ){
            fast = fast -> next -> next;
            slow = slow -> next;
            
        }
        return fast == slow;
    }
};