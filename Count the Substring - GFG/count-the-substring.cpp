//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{

public:

void merge(vector<long long>& v, long long left,

           long long mid, long long right, long long& inversions)

{

    vector<long long> temp(right - left + 1);

 

    long long i = left;

    long long j = mid + 1;

    long long k = 0;

    long long cnt = 0;

 

    while (i <= mid && j <= right) {

        if (v[i] <= v[j]) {

            temp[k++] = v[i++];

        }

        else {

            // Counting inversions

            inversions += (mid - i + 1);

 

            temp[k++] = v[j++];

        }

    }

 

    while (i <= mid)

        temp[k++] = v[i++];

 

    while (j <= right)

        temp[k++] = v[j++];

 

    k = 0;

    for (long long a = left; a <= right; a++) {

        v[a] = temp[k++];

    }

}

 

// Function to implement merge sort

void mergeSort(vector<long long>& v, long long left,

               long long right, long long& inversions)

{

    if (left < right) {

        long long mid = (left + right) / 2;

 

        mergeSort(v, left, mid, inversions);

        mergeSort(v, mid + 1, right, inversions);

        merge(v, left, mid, right, inversions);

    }

}

 

// Function to calculate number of

// inversions in a given array

long long CountInversions(vector<long long>& v)

{

    long long n = v.size();

    long long inversions = 0;

 

    // Calculate the number of inversions

    mergeSort(v, 0, n - 1, inversions);

 

    // Return the number of inversions

    return inversions;

}

 

// Function to count the number of

// substrings that contains more 1s than 0s

long long countSubstring(string& input)

{

    long long n = input.length();

 

    vector<long long> nums(n);

 

    for (long long i = 0; i < n; i++) {

        nums[i] = input[i] - '0';

 

        if (nums[i] == 0)

            nums[i] = -1;

    }

 

    // Stores the prefix sum array

    vector<long long> pref(n);

 

    long long sum = 0;

 

    for (long long i = 0; i < n; i++) {

        sum += nums[i];

        pref[i] = sum;

    }

 

    long long cnt = 0;

 

    // Stores the count of valid substrings

    for (long long i = 0; i < n; i++) {

        if (pref[i] > 0)

            cnt++;

    }

 

    reverse(pref.begin(), pref.end());

 

    long long inversions = CountInversions(pref);

 

    long long ans = cnt + inversions;

 

    return ans;

}

};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends