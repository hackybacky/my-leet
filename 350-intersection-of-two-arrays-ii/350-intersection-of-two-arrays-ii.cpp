class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //sort(nums2.begin() ,nums2.end());
        vector<int> ans;
        
        for(int i=0; i<nums1.size(); i++){
            auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            if(it!=nums2.end())ans.push_back(*it),*it=1e9;
        }
        
        return ans;
        
    }
};