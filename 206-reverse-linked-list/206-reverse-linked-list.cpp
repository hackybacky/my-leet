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
    ListNode *ans;
    void reverse(ListNode * cur, ListNode*prev){
        if(cur==nullptr){ans=prev;return;}
        reverse(cur->next,cur);
        cur->next=prev;
    }
    ListNode* reverseList(ListNode* head) {
        auto prev= new ListNode();
        prev=NULL;
        reverse(head,prev);
        return ans;
    }
};