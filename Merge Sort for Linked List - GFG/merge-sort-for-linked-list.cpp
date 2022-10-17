//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node * merge(Node * head , Node * head2){
        if(!head){
            return head2;
        }
        if(!head2){
            return head;
        }
        Node * cur = new Node(-1);
        Node * t = cur;
        while(head and head2){
            if(head -> data <= head2 -> data){
                cur -> next = head ;
                head = head -> next;
            }
            else{
                cur -> next = head2;
                head2 = head2 -> next;
            }
            cur = cur -> next ;
        }
        if(head)cur -> next = head;
        else cur -> next = head2;
        return t -> next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or head -> next == NULL){
            return head;
        }
        auto slow = head , fast = head -> next ;
        while(fast and fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        fast = slow -> next;
        slow -> next = NULL;
        return merge(mergeSort(head)  , mergeSort(fast));
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends