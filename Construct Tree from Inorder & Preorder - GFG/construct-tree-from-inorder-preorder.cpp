//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node * dfs(int in[] , int pre[] , int lp , int rp , int l , int r){
        if(l > r){
            return NULL;
        }
        Node * root = new Node(pre[lp]);
        // root -> data = pre[lp];
        int j = l ;
        while(in[j] != pre[lp]){
            j++;
        }
        int ele = j - l;
        root -> left = dfs(in , pre , lp + 1 , lp + ele , l , j - 1 );
        root -> right = dfs(in , pre , lp + ele + 1 , rp , j + 1 , r);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n , int l = 0 , int cur = 0)
    {
        return dfs(in  , pre , 0 , n - 1 , 0 , n - 1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends