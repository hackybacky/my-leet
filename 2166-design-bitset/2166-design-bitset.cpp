class Bitset {
public:
    string s;
    bool al;
    int on;
    int cn1=0;
    int n;
    set<int> onep,zerop;
    int flipc;
    Bitset(int size) {
        for(int i=0; i<size; i++){
            s+='0';
            zerop.insert(i);
        }
        al=false;
        on=false;
        cn1=0;
        flipc=0;
        n=size;
        
    }
    
    void fix(int idx) {
        if(flipc%2==0){
            auto it =zerop.find(idx);
            if(it!=zerop.end())zerop.erase(it),on++;
            onep.insert(idx);
        }
        else{
            auto it = onep.find(idx);
            if(it!=onep.end())onep.erase(it),on++;
            zerop.insert(idx);
        }
        
    }
    
    void unfix(int idx) {
        if(flipc%2==1){
            auto it =zerop.find(idx);
            if(it!=zerop.end())zerop.erase(it),on--;
            onep.insert(idx);
        }
        else{
            auto it = onep.find(idx);
            if(it!=onep.end())onep.erase(it),on--;
            zerop.insert(idx);
        }
        
    }
    
    void flip() {
        flipc++;
        on=n-on;
        
    }
    
    bool all() {
        return n==on;
    }
    
    bool one() {
        return on>=1;
        
    }
    
    int count() {
        return on;
        
    }
    
    string toString() {
        
        string l(n,'0');
        if(flipc%2==0){
            for(auto it : zerop)l[it]='0';
            for(auto it :onep)l[it]='1';
        }
        else{
           
            for(auto it : zerop)l[it]='1';
            for(auto it :onep)l[it]='0';
            
        }
        return l;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */