//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node * reverse( Node * head){
        if(!head or !head -> next)
            return head;
        auto node = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return node;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here 
        
        auto slow = head , fast = head -> next;
        
        while(fast and fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        auto start_second = slow -> next;
        Node * head2 = reverse(start_second);
        
        while(head2){
            if(head2 -> data != head -> data){
                return false;
            }
            head2 = head2 -> next;
            head = head -> next;
        }
        return true;
        
                                                                                           
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends