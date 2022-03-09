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
   ListNode* deleteDuplicates(ListNode* head) {
        
         if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *iter=new ListNode();
        ListNode * ans=iter;
       // cout<<head->val<<endl;
        
        while(head!=NULL){
            if(head->next && head->val ==head->next->val){
                int curval=head->val;
               
                while(head!=NULL and head->val==curval){
                    head=head->next;
                }
            }
            else{
                iter->next=head;
                
                iter=iter->next;
                head=head->next;
            }
          
           
        }
        iter->next=nullptr;
        return ans->next;
    }
};