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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int len =1;
        
        auto node = head;
        
        while(node and node ->next){
            node = node ->next;
            len++;
        }
        node ->next= head;
        int req = len -k%len;
        node = head;
        for(int i=0; i<req-1; i++){
            node = node ->next;
        }
        //cout<<node->val<<" "<<req<<endl;
        auto nhead = node ->next;
        node -> next =NULL;
        return nhead;
    }
};