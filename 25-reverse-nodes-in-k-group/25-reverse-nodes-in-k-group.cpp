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
        auto node = head ;
        int cnt=0;
        while(node and cnt!=k){
            node = node->next;
            cnt++;
        }
        auto h = head;
        if(cnt==k){
            node = reverseKGroup(node , k);
            while(cnt--){
                auto nxt = h->next;
                h->next=node;
                node=h;
                h=nxt;
            }
            h=node;
        }
        return h;
    }
};