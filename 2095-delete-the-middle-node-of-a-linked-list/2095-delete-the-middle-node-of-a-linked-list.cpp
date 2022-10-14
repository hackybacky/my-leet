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
    ListNode* deleteMiddle(ListNode* head) {
        
        auto slow = head;
        auto fast = head;
        ListNode * p = NULL;
        while(fast and fast -> next){
            p = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
            
        }
        if(slow == fast){
            return NULL;
        }
        if(slow){
            p -> next = slow -> next;
        }
        return head;
    }
};