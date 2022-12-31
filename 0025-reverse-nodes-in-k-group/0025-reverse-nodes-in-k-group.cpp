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
        if(!head or !head -> next)return head;
        int node = 0;
        auto curh = head;
        while(node < k and curh)curh = curh -> next , node++;
        if(node < k)return head;
        int dk = k;
        auto cur = head;
        auto agla = cur -> next;
        while(cur and agla and dk > 1){
            auto nnxt = agla -> next;
            agla -> next = cur;
            cur = agla;
            agla = nnxt;
            dk--;
        }
        head -> next = nullptr;
        if(dk == 1 and agla ){
            head -> next = reverseKGroup(agla, k);
                // return reverseKGroup(cur -> next , k);
                cout << agla  -> val << endl;
        }
        return cur;
        
    }
};