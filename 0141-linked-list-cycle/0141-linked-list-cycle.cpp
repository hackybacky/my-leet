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
        if(!head)return NULL;
        auto slow = head , fast = head -> next;
        
        while(fast and fast -> next and fast != slow){
            fast = fast -> next -> next;
            slow = slow -> next;
            
        }
        return slow == fast;
    }
};