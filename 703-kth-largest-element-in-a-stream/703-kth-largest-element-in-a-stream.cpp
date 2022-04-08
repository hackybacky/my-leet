class KthLargest {
public:
    int K;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        sort(nums.rbegin(),nums.rend());
        for(int i=0; i<min(k,(int)nums.size()); i++){
            pq.push(-nums[i]);
            //cout<<nums[i]<<endl;
        }
    }
    
    int add(int val) {
        
        if(pq.size()<K)pq.push(-val);
        else{
            if(val>-pq.top()){
                pq.pop();
                pq.push(-val);
            }
        }
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */