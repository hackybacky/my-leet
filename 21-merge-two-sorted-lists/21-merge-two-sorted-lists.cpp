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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2)return NULL;
        ListNode *m_list=new(ListNode);
        ListNode *head=m_list;
        while(list1 and list2){
            
            if(list1->val>list2->val){
                m_list->val=list2->val;
                list2=list2->next;
            }
            else{
                m_list->val=list1->val;
                list1=list1->next;
            }
        if(list1 or list2)
            m_list->next=new(ListNode),
            m_list=m_list->next;
        }
        if(list2!=NULL)swap(list1,list2);
        while(list1){
            m_list->val=list1->val;
            list1=list1->next;
            
            
            
            
            
            
            
            
            
            if(list1)
                m_list->next=new(ListNode),
                m_list=m_list->next;
        }
        return head;
        
    }
};