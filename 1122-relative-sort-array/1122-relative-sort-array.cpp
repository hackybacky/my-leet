class Solution {

public:



     static  bool cmp(pair<int,int>p1,pair<int,int>p2)

        {

        if(p1.second!=INT_MAX or p2.second!=INT_MAX)

            { 

            return p1.second<p2.second;

            }

        else

            {

             return p1.first<p2.first;

            }

        }



    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)

    {

        int rank[1001];

        

        for(int i=0;i<1001;i++)

        {

            rank[i]=INT_MAX;

        } 

        

        for(int i=0;i<arr2.size();i++)

        {

            rank[arr2[i]]=i;

        }

        

        vector<pair<int,int>>v;

        

        vector<int>ans;

        

        for(int i=0;i<arr1.size();i++)

        {
            cout<<rank[arr1[i]]<<" "<<arr1[i]<<endl;
           v.push_back({arr1[i],rank[arr1[i]]});

        }

        

        sort(v.begin(),v.end(),cmp);

    

        for(int i=0;i<arr1.size();i++)

        {

            ans.push_back(v[i].first);

        }

        return ans;

    }

};