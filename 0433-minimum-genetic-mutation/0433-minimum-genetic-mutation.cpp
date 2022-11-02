class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        priority_queue<pair<int , string >> pq;
        unordered_map<string , bool > mp;
        unordered_map<string , int > dis;
        for(auto it : bank){
            mp[it] = true;
        }
        pq.push({0 , start});
        
        while(!pq.empty()){
            
            auto t = pq.top();
            int distance = t.first;
            string s = t.second;
            if(s == end){
                return distance ;
            }
            // cout << "hello" << endl;
            pq.pop();
            
            for(int i = 0 ; i < s.size() ; i++){
                char current = s[i];
                
                for(char c = 'A' ; c <= 'Z' ; c++){
                    s[i] = c;
                    // cout <<s  << endl;
                    if(mp.find(s) != mp.end() ){
                        if(dis.find(s) == dis.end())
                            dis[s] = distance + 1 , pq.push({dis[s] , s}) ;
                        else if(dis[s] > distance + 1){
                            dis[s] =distance + 1;
                            pq.push({dis[s] , s});
                        }
                        
                    }
                }
                s[i] = current;
            }
        }
        return -1;
    }
};