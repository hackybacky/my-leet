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
    bool check(ListNode * head , ListNode *&last){
        if(!head)return true;
        bool c = check(head -> next , last);
        bool cr = head -> val == last -> val;
        last = last -> next;
        return c & cr;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * last = NULL;
        return check(head , head);
    }
};