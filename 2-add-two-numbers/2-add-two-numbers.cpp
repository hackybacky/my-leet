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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *node=new(ListNode);
        auto head=node;
        int carry =0;
        
        while(l1 or l2 or carry){
            int first ,second;
            if(l1){
                first=l1->val;
                l1=l1->next;
                
            }
            else first=0;
            
            if(l2){
                second=l2->val;
                l2=l2->next;
            }
            else second =0;
            
            int su =first+second +carry;
             carry=su/10;
            if(l1 or l2 or carry)node->next=new(ListNode);
            node->val=su%10;
           // cout<<node->val<<endl;
            node=node->next;
            
           
        }
        return head;
        
    }
};