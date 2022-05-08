/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int curIndi;
    // NestedInteger curInteger ;
    vector<int>ans;
    void dfs(vector<NestedInteger>list){
        
        for(auto it : list){
            if(it.isInteger()){
                ans.push_back(it.getInteger());
            }
            else {
                dfs( it.getList() );
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        // for(auto it : ans)cout<<it<<" ";
        curIndi=0;
        
    }
    
    int next() {
        return ans[curIndi++];
    }
    
    bool hasNext() {
       return  curIndi<(int)ans.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */