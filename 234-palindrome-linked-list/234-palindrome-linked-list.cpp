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
    ListNode * tmp;
    bool check(ListNode * head){
        if(!head)return true;
        
        bool flag = check( head->next) and (head->val==tmp->val);
        tmp=tmp->next;
        return flag;
    }
    bool isPalindrome(ListNode* head) {
        tmp = head;
        return check(head);
    }
};