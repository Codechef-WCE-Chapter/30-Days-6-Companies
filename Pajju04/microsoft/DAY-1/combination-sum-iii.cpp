//_________________________________________________________//
#include <bits/stdc++.h>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NULL);
#define ll                long long
#define vl                vector<long long>
#define vi                vector<int>
#define vp                vector<pair<long long , long long>>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define f_ab(i, a, b)     for (auto i = a; i < b; ++i)
#define f_rab(i, a, b)    for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
//_______________________________________________________//

using namespace std;
class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9);
        for(int i = 0 ; i < 9 ; ++i){
            arr[i] = i+1;
        }
        memo(arr,k,n,0);
        return res;
    }
    void memo(vector<int>& arr, int len , int target, int idx){
        if(len == 0) {
            if(target == 0) res.push_back(temp);
            return;
        }
        if(idx > 8) return;
        temp.push_back(arr[idx]);
        memo(arr,len-1,target-arr[idx],idx+1);
        temp.pop_back();
        memo(arr,len,target,idx+1);
    }
};