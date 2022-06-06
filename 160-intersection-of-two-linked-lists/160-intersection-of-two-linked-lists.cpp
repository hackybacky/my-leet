/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        auto a = headA;
        auto b = headB;
        int cnt=0;
        while(a!=b and cnt<=2){
            a=a->next;
            b=b->next;
            if(a==NULL)a=headB,cnt++;
            if(b==NULL )b= headA,cnt++;
        }
        return a==b?a:NULL;
    }
};