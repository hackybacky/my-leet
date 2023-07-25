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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        auto d = head;
        auto nn = head -> next;
        while(head and nn){
            auto nxt = nn -> next;
            nn -> next = head;
            head = nn;
            nn = nxt;
        }
        d -> next = NULL;
        return head;
    }
};