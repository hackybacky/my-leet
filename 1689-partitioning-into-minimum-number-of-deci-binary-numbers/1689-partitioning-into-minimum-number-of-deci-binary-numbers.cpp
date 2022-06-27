class Solution {
public:
    int minPartitions(string n) {
        
       auto it = *max_element(n.begin(),n.end());
        return it-'0';
    }
};