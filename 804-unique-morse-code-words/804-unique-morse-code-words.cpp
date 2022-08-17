class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>s;
        for(auto it : words){
            string cur = "";
            for(auto it2: it){
                cur+=v[(it2-'a')];
            }
            s.insert(cur);
        }
        return s.size();;
    }
};