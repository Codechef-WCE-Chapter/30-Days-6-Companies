#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define MOD 1000000007

/*
TLDR:
Overall, the approach of the function is to iterate through the array twice, first to find the start and end of the unsorted subarray, and then to find the minimum and maximum values of the subarray and adjust the start and end pointers accordingly.

Approach:
1. Start by initializing two pointers, `start` and `end`, to the first and last element of array respectivley.
2. Iterate through the array from first element, looking for the first pair of elements that are out of order. When we find such a pair, assigns the index of the first element to the variable `start`.
3. Do same iteration to find `end` of the unsorted array, but this time start the iteration from last element.
4. After finding the start and end of the unsorted subarray, now find the minimum and maximum values of the subarray and assigns them to m and M respectively.
5. Then iterate through the array again from first element upto `start` and check if any element is smaller than m.
6. Same to find if any element is greater than M from `end` to last element of the array.
7. Return the length of the unsorted subarray.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& A){
        int n = A.size(), start = 0, end = n-1, m = A[0], M = A[0];     // Initialize the required variables 
        
        // To find the `start` on unsorted subarray
        for(start=0; start<n-1; start++){
            if(A[start]>A[start+1]) {break;}
        }

        // To find the `end` of unsorted subarray
        for(end=n-1; end>1; end--){
            if(A[end]<A[end-1]){ break;}
        }
        
        // To find the min and max element of the unsorted subarray
        m = A[start]; M = A[start];
        for(int i=start; i<=end; i++){
            if(A[i]>M) M = A[i];
            else if(A[i]<m) m = A[i];
        }

        // To adjust the pointers
        for(int i=0; i<start; i++){
            if(A[i]>m){
                start = i;
                break;
            }
        }
        
        for(int i=n-1; i>=end; i--){
            if(A[i]<M){
                end = i;
                break;
            }
        }
        
        return end-start+1;
        
    }
};

void solve(){
    int n = 7;
    vector<int> A = {2, 6, 4, 8, 10, 9, 15};
    
    Solution obj;
    cout<<obj.findUnsortedSubarray(A)<<endl;
    
    return;
}

int main(){
    fastIO
    ll t;
    cin>>t;
           
    while(t--){
        solve();
    }
              
    return 0;
}
