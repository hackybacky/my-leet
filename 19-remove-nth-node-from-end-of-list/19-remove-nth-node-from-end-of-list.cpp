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
    auto calculate_size(ListNode *head){
        int cnt=0;
        while(head){
            head=head->next;
            cnt++;
        }
        return cnt;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int siz=calculate_size(head);
        int front=siz-n;
        ListNode* node=head;
        ListNode *prev=NULL;
        if(head->next==NULL){
            return NULL;
        }
        while(front){
            prev=head;
            head=head->next;
            
            front--;
        }
        
        if(prev==NULL){
            return head->next;
        }
        else{
            prev->next=head->next;
        }
        
        return node;
    }
};