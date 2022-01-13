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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> v;
        int n=lists.size();
        if(n==0)return NULL;
        for(int i=0 ; i< n  ;i++){
            ListNode *head=lists[i];
            while(head){
                v.push_back(head->val);
                head=head->next;
            }
        }
        n=v.size();
        if(n==0)return NULL;
        sort(v.begin(),v.end());
        ListNode *ans= new(ListNode);
        auto he=ans;
        for(int i=0 ;i < n-1; i++){
            ans->val=v[i];
            ans->next=new(ListNode);
            ans=ans->next;
        }
        ans->val=v[n-1];
        return he;
    }
};