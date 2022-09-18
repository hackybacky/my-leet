class Solution {
public:
    struct Node{
        Node * links[2];
        int cnt = 0;
        int val = 0;
        void put(int bit ){
            links[bit] = new Node();
        }
        bool contains(int bit ){
            // cout << bit << endl;
            return links[bit] != NULL;
        }
        Node * getNext(int bit){
            return links[bit];
        }
        void increaseCount(int set , int d){
            links[set]->cnt += d;
            
        }
        int getCount(int bit){
            return links[bit] -> cnt;
        }
        
    };
    class Trie{
        public:
              Node * root;  
              Trie(){
                  root = new Node();
              }  
              void update(int num , int d){
                  Node * tmp = root;
                  for(int i = 18 ; i>=0 ; i--){
                      int set = (bool)(num & (1<<i));
                      // cout << set << " " << num <<endl;
                      if(tmp -> contains(set) == false){
                          tmp -> put(set);
                      }
                      tmp -> increaseCount(set ,d );
                      tmp = tmp -> getNext(set);
                  }
                  tmp -> val = num;
                  
              }  
              int getMaxi(int num)  {
                  Node * tmp = root;
                  int result = 0;
                  for(int i = 18 ; i >=0 ; i--){
                      int set = (bool)(num & (1<<i));
                      // cout << (set ^ 1) << " " << num <<" "<<set<<endl;
                      if( tmp -> contains(1 - set) and tmp ->getCount(1 - set) > 0 ){
                          tmp = tmp -> getNext(1 - set);
                      }
                      else if(tmp -> contains(set)){
                          tmp = tmp -> getNext(set);
                      }
                  }
                  
                  return (tmp -> val) ^ num;
              }
    };
    
    Trie trie;
    unordered_map<int,vector<pair<int,int>>>query;
    vector<int>ans;
    unordered_map<int,vector<int>>graph;
    void dfs(int node , int par){
        trie.update(node , 1);
        for(auto it : query[node]){
            ans[it.second] = trie.getMaxi(it.first);
        }
        
        for(auto it : graph[node]){
            // if(it != par){
                dfs( it , node);
            // }
        }
        
        trie.update(node , -1);
    }
    
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        int root;
        for(int i = 0 ; i < n ; i++){
            if(parents[i] == -1){
                root = i;
                continue;
            }
                
            graph[parents[i]].push_back(i);
            // graph[i].push_back(parents[i]);
        }
        ans.assign(queries.size() , 0);
        for(int i = 0 ; i < queries.size() ; i++){
            auto it = queries[i];
            int node = it[0];
            int val = it[1];
            query[node].push_back({val , i});
        }
        dfs(root , -1);
        return ans;
        
    }
};