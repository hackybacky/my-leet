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
    ListNode * mergetwolist(ListNode * l , ListNode *l2){
        auto head = new ListNode();
        auto root = head;
        while(l and l2){
            if(l->val<=l2->val){
                head->next=l;
                l=l->next;
            }
            else head->next=l2 , l2=l2->next;
            head=head->next;
        }
        if(l)head->next=l;
        else head ->next = l2;
        return root->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)return nullptr;
        if(lists.size()==1)return lists[0];
        auto nl = mergetwolist(lists[0],lists[1]);
        // return nl;
        for(int i=2;i<lists.size(); i++){
            auto n = mergetwolist(nl, lists[i]);
            nl = n;
        }
            
        return nl;
        
    }
};