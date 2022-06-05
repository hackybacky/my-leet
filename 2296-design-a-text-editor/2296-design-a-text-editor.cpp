class TextEditor {
public:
    deque<char>ba,front;
    TextEditor() {
        
    }
    
    void addText(string text) {
        
        for(auto it : text)ba.push_back(it);
        
    }
    
    int deleteText(int k) {
        int ans=0;
        while(k-- and !ba.empty()){
            ba.pop_back();ans++;
        }
        return ans;
    }
    
    string shift_left(){
        int i=0;
        deque<char> v;
        string ans="";
        while(!ba.empty() and i<10 ){
            v.push_front(ba.back());
            ba.pop_back();
            i++;
        }
        while(!v.empty()){
            ans+=v.front();
            ba.push_back(v.front());
            v.pop_front();
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        for(int i=0;i<k and ba.empty()==false;i++){
            front.push_front(ba.back());
            ba.pop_back();
        }
                    
        return shift_left();
    }
    
    string cursorRight(int k) {
        for(int i=0;i<k and front.empty()==false;i++){
            ba.push_back(front.front());
            front.pop_front();
        }
        
        return shift_left();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */