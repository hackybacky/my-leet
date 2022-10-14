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
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * prev = NULL;
        ListNode * cur = head ;
        ListNode * next;
        int cnt = 0;
        int c = 0;
        auto d = head;
        while(d){
            d = d -> next;
            c++;
        }
        if(c < k){
            return head;
        }
        while(cur != NULL and cnt < k){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        if(next and cnt == k ){
            head -> next = reverseKGroup(next , k);
        }
        return prev;
    }
};