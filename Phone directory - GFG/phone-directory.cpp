//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Node {
        Node * links[26];
        bool contains(char c){
            return links[c - 'a'] != NULL;
        }
        vector<string>cur;
        void push(string & s){
            // cout << s << endl;
            cur.push_back(s);
        }
        
        
    };
    class Trie{
        public :
            Node * root;
            Trie(){
                root = new Node();
            }
            void insert(string & word){
                auto node = root;
                for(auto it : word){
                    if(node -> contains(it) == false){
                        node -> links[it - 'a'] = new Node();
                    }
                    // cout << "hhare" << endl;
                    node = node ->links[it - 'a'];
                    auto fd = find(node -> cur.begin() , node ->cur.end() , word);
                    if(fd == node -> cur.end())
                    node->push(word);
                }
            }
            vector<vector<string>> search(string & word){
                auto node = root;
                vector<vector<string>>ans;
                for(auto it : word){
                    if(node -> contains(it) == false){
                        return ans;
                    }
                    node = node -> links[it - 'a'];
                    ans.push_back(node -> cur);
                }
                return ans;
            }
    };
class Solution{
public:
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // sort(contact , contact + n);
        Trie trie;
        for(int i = 0 ; i < n ;i++){
            trie.insert(contact[i]);
        }
        auto ans = trie.search(s);
        for(auto &it : ans){
            sort(it.begin() , it.end());
        }
        // sort(ans.begin() ,ans.end());
        for(int i = ans.size() ; i < s.size() ; i++){
            ans.push_back({"0"});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends