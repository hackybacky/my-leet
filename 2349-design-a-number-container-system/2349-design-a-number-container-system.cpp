class NumberContainers {
public:


  map<int,int> m;
    NumberContainers() {
      
        
    }
    
    void change(int index, int number) {
      m[index]=number;
        
    }
    
    int find(int number) {
         int ans=-1;
        for(auto it:m){
            if(it.second==number){
                ans=it.first;
                break;
            }
        }
         
        return ans;
        
    }
};
