class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string > st;
        int n = path.size();
        int i=0;
        while(i<n){
            
            if(path[i]=='/'){i++;continue;}
            string temp="";
            while(i<n and  path[i]!='/'  ){
                temp+=path[i];
                i++;
            }
            if(temp==".")continue;
            else if(temp==".."){
                if(!st.empty())st.pop();
            }
            else st.push(temp);
            i++;
        }
        string lans="";
        while(!st.empty()){
            lans='/'+st.top()+lans;
            st.pop();
        }
        if(lans.size()==0)return "/";
        return lans;
        
    }
};