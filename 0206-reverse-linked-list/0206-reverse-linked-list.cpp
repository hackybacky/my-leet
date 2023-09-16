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
    // auto reverse(ListNode *head){
    //     if(!head or ! head -> next)return head;
    //     auto rv = reverse(head -> next);
    //     head -> next -> next = head;
    //     head -> next = NULL;
    //     return rv;
    // }
    ListNode* reverseList(ListNode* head) {
        if(!head or ! head -> next)return head;
        auto rv = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return rv;
    }
};