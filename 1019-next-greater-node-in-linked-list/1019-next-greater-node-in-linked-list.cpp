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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<ListNode *> st;
        auto node = head;
        int cnt = 0;
        while(node){
            int cur = node -> val;
            while(!st.empty() and st.top()-> val < cur){
                st.top()-> val = cur;
                st.pop();
            }
            st.push(node);
            node = node -> next;
        }
        while(st.empty() == false){
            st.top()-> val = 0;
            st.pop();
        }
        vector<int>ans;
        node = head;
        while(node){
            ans.push_back(node -> val);
            node = node -> next;
        }
        return ans;
    }
};