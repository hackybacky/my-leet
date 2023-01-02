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
    ListNode * reverse(ListNode * head){
        if(!head or !head -> next)return head;
        auto node = reverse(head -> next);
        
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
    void reorderList(ListNode* head) {
        if(!head or !head -> next)return;
        
        auto slow = head , fast = head -> next;
        while(fast and fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        auto reverse_head = reverse(slow -> next);
        slow -> next = NULL;
        slow = head;
        int parity = 0;
        auto node = new ListNode(-1);
        while(slow or reverse_head){
            if(parity == 0){
                node -> next = slow;
                slow = slow -> next;
            }
            else{
                node -> next = reverse_head;
                reverse_head = reverse_head -> next;
            }
            node = node -> next;
            parity ^= 1;
        }
        
        
        
    }
};