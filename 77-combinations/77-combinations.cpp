class Solution {

public:

    

    void fun(int arr[],vector<vector<int>>& matrix,vector<int>&v,int index,int k,int n){

        if(v.size()==k){

            matrix.push_back(v);

            return;

        }

        if(index==n){

            if(v.size()==k){

                matrix.push_back(v);

                return;

            }

            return;

        }

        

        for(int i=index;i<n;i++){

            v.push_back(arr[i]);

            fun(arr,matrix,v,i+1,k,n);

            v.pop_back();

        }

    }

    

    

    vector<vector<int>> combine(int n, int k) {

       int arr[n];

       for(int i=0;i<n;i++){

           arr[i]=i+1;

       }

        vector<vector<int>>matrix;

        vector<int>v;

        fun(arr,matrix,v,0,k,n);

        return matrix;

    }

};