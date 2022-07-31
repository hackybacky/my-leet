class NumArray {
public:
    template <typename T>
class segtree{
public:

  struct item{
    T val;
  };
  T sentinel_val;// the out of range value
  vector<item> arr;//[4*MAXN]; // MAXN = 2e5
  
  T N;
  
  void init(const T  sz){
    N = 1;
    sentinel_val = 0;
    // for sum:sentinal_val = 0, min = 1e17, max = -1e7, XOR = 0, gcd = 0

    
    while(N < sz) N <<= 1;
    arr.resize(2*N);

    for(int i = 0; i < 2*N; i++) arr[i].val = sentinel_val; 
  }
  
  T combine(T a, T b){
    // if(a == -1) return b;
    // if(b == -1) return a;
    return (a+b); // for sum
    //return min(a,b); // for min
    //return max(a,b); // for max
    //return __gcd(a,b); // for gcd
    // return a^b; // for XOR
  }
  
  void build(vector<T> &vec,int index, int l, int r){
    if(l == r){
      if(l >= (int)vec.size()) return;
      
      arr[index].val = vec[l];
      return;
    }
    int m = (l+r)/2;
    
    build(vec,2*index,l,m);
    build(vec,2*index+1,m+1,r);
    
    arr[index].val = combine(arr[2*index].val,arr[2*index+1].val);
  }
  void build(vector<T> &vec){
    build(vec,1,0,N-1);
  }
  
  // 0 based indexing for upd_index 
  void update(int index, int l, int r, int upd_index,T upd_val){
    if(l > upd_index || upd_index > r) return;
    
    if(l == r){
      arr[index].val = upd_val;
      return;
    }
    
    int m = (l+r)/2;
    
    update(2*index,l,m,upd_index,upd_val);
    update(2*index+1,m+1,r,upd_index,upd_val);
    
    arr[index].val = combine(arr[2*index].val,arr[2*index+1].val);
  }
  
  // 0 based indexing for upd_index
  void update(int upd_index, T upd_val){
    update(1,0,N-1,upd_index,upd_val);
  }
  
  T query(int index, int l, int r, int lx, int rx){
    if(l > rx || lx > r) return sentinel_val;
    
    if(lx <= l && r <= rx){
      return arr[index].val;
    }
    int m = (l+r)/2;
    
    return combine(query(2*index,l,m,lx,rx),query(2*index+1,m+1,r,lx,rx));
  }
  
  // assuming lx and rx are 0 based
  // query returns the answer in the range [lx,rx]
  // including lx and rx
  T query(int lx, int rx){
    return query(1,0,N-1,lx,rx);
  }
};

segtree<int> s;

    
    NumArray(vector<int>& nums) {
        s.init(4*nums.size());
        s.build(nums);
    }
    
    void update(int index, int val) {
        s.update(index,val);
    }
    
    int sumRange(int left, int right) {
        cout<<s.query(0,0)<<endl;
        return s.query(left,right);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */