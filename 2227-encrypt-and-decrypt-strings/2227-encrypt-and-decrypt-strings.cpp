class Encrypter {
public:
    unordered_map<char,string > en;
    unordered_map<string,int> dc;
    
    Encrypter(vector<char>& keys, vector<string>& value, vector<string>& dictionary) {
        
        for(int i=0; i<keys.size();i++){
            en[keys[i]]=value[i];
        }
        
        for(auto it : dictionary){
            string cur="";
            for(auto i : it){
                cur+=en[i];
            }
            dc[cur]++;
        }
    }
    
    string encrypt(string word1) {
        string cur ="";
        for(auto it : word1){
            cur+=en[it];
        }
        return cur;
    }
    
    int decrypt(string word2) {
        return dc[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */