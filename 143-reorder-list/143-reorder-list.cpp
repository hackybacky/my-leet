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
    ListNode* reverse(ListNode *root){
        
        if(!root)return NULL;
        ListNode *prev=nullptr;
        ListNode *cur = root;
        if(!cur)return root;
        
        while( cur){
            ListNode * temp = cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        
        return prev;
        
    }
    void reorderList(ListNode* head) {
        
        if(head->next==nullptr)return;
        ListNode *slow=head , *fast=head->next->next;
        // slow=fast;
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        auto rev=reverse(slow->next);
        slow->next=nullptr;
        ListNode * cur=head;
        ListNode *p;
        while(cur ){
            
            auto t = cur->next;
            cur->next=rev;
            p=cur;
            cur=t;
            auto r=rev->next;
            if(cur)
            rev->next=cur;
            rev=r;
            
        }
        if(rev){
            cout<<rev->val;
        }
    }
};