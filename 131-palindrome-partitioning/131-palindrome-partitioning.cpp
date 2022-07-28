class Solution {

public:

    

    bool is_pallindrome(string temp){

        int i=0;

        int j=temp.size()-1;

        while(i<=j){

           if(temp[i]!=temp[j]){

               return false;

           }

            i++;

            j--;

        }

        return true;

    }

    

    

    void generate(vector<vector<string>>& matrix,vector<string>& ans,int index,string&s){

        if(index==s.size()){

            matrix.push_back(ans);

            return;

        }

        for(int j=index;j<s.size();j++){

            string temp=s.substr(index,j-index+1);

            if(is_pallindrome(temp)){

                ans.push_back(temp);

                generate(matrix,ans,j+1,s);

                ans.pop_back();

            }

        }

    }

    

    vector<vector<string>> partition(string s) {

        vector<vector<string>>matrix;

        vector<string>temp;

        generate(matrix,temp,0,s);

        return matrix;

    }

};