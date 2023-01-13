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
vector<vector<int>>dp;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; ++i){
            dp.resize(n);
            vector<int>res = memo(nums,i);
            if(res.size() > ans.size()){
                ans = res;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>memo(vector<int>& nums, int i){
        if(i >= nums.size()) return {};
        if(dp[i].size() != 0) return dp[i];
        vector<int>ans;
        for(int j = i+1; j < nums.size(); ++j){
            if(nums[j]%nums[i] == 0){
                vector<int>temp = memo(nums,j);
                if(temp.size() > ans.size()) ans = temp;
            }
        }
        ans.push_back(nums[i]);
        return dp[i] = ans;
    }
};