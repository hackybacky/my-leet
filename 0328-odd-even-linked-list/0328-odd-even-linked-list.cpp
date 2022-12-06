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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * odd = new ListNode(-1) ,* even = new ListNode(-1);
        auto dodd = odd;
        auto deven = even;
        auto node = head;
        int cur = 1;
        while(node){
            if(cur % 2 == 1){
                odd -> next = node;
                odd = odd -> next;
            }
            else{
                even -> next = node;
                even = even -> next;
            }
            cur++;
            node = node -> next;
        }

        odd -> next = deven -> next;
        even -> next = nullptr;
        return dodd -> next;


    }
};