class Solution {
public:

vector<int>ans;
void merge(vector<pair<int,int>>&arr , int l ,int mid , int r){
	
	vector<pair<int,int>> a(r-l+1);
	int i = l ;
	int j = mid+1;
	int k=0;

    int cnt=0;
	while(i<=mid and j<=r){
		
		//cout<<arr[j]<<" "<<arr[i]<<endl;
		if(arr[i].first <=arr[j].first )a[k]=arr[i],ans[arr[i].second]+=cnt,i++;
		else {a[k]=arr[j],j++;
              cnt++;
		}
		k++;
	}
    while(i<=mid){
        a[k]=arr[i];
        ans[arr[i].second]+=cnt;
        i++;
        k++;
    }
    
    while(j<=r){
        a[k]=arr[j];
        j++;
        k++;
    }
	
	for(int p=l,j=0; p<=r; p++,j++){
		//cout<<arr[p]<<endl;
		arr[p]=a[j];
	}
}

void mergesort(vector<pair<int,int>>&arr , int l ,int r){
	if(l>=r){
		return ;
	}
	int mid =(l+r)/2;
	
	mergesort(arr, l , mid );
	mergesort(arr , mid +1 , r);
	merge(arr , l , mid , r );
}
    vector<int> countSmaller(vector<int>& nums) {
        ans.assign(nums.size(),0);
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back(make_pair(nums[i],i));
        }
        mergesort(arr,0,nums.size()-1);
        for(auto it : arr)cout<<it.first<<" "<<it.second<<endl;
        
        return ans;
    }
};