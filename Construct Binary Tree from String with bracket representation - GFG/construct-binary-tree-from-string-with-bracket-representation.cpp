//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    int find_mid(string & s , int l , int r){
        stack<char > st;
        for(int i = l ; i <=r ; i++){
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')'){
                st.pop();
                if(st.empty()){
                    return i;
                }
            }
        }
        return -1;
    }
    Node * contruct(string &s ,  int l , int r){
        if(l > r){
            return NULL;
        }
        
        int mid = find_mid(s , l ,  r ); 
        string d = "";
        int t = l ;
        while(t <= r and s[t] != ')' and  s[t] != '(')
            d += s[t++];
        Node * root = new Node(stoi(d));
        // cout << root ->data <<" " << mid << endl;
        if(mid != -1)root -> left = contruct(s , t + 1 , mid - 1);
        if(mid != -1)root -> right = contruct(s , mid + 2 , r - 1);
        return root;
        
    }
    Node *treeFromString(string str)
    {
        // code here
        return contruct(str , 0 , str.size() - 1);
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends