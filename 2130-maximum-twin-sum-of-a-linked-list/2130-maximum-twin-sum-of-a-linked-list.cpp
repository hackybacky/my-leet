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
    ListNode * find_mid(ListNode * head){
        
        auto slow = head , fast = head -> next;
        
        while(fast and fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        // cout << slow -> val << endl;
        return slow -> next;
        
    }
    ListNode * reverse_list(ListNode * root){
        if(!root or !root -> next){
            return root;
        }
        auto rev = reverse_list(root -> next);
        root -> next -> next = root;
        root -> next = NULL;
        return rev;
    }
    int pairSum(ListNode* head) {
        
        
        auto mid = find_mid(head);
        auto rev = reverse_list(mid);
        int sum = 0 ;
        while(rev){
            int cur = rev -> val + head -> val;
            sum = max(sum , cur);
            rev = rev -> next;
            head = head -> next;
        }
        return sum ;
    }
};