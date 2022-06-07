// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode * head;
    TNode * recur( LNode *head ){
        if(head==NULL)return NULL;
        if(!head->next)return new TNode(head->data);
        auto slow = head;
        auto fast = head;
        
        LNode * slowprev=NULL;
        while( fast and fast->next){
            slowprev= slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        
        
        int d  = slow -> data;
        TNode* root = new TNode(d);
        // if(slowprev)
        slowprev->next=NULL;
        
        LNode * ne = nullptr;
         if(slow)ne=slow->next,
        slow->next=NULL;
        
        root->left=recur(head);
        root->right= recur(ne);
        return root;
        
        
    }
    TNode* sortedListToBST(LNode *head) {
        //code here
        return recur(head);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends