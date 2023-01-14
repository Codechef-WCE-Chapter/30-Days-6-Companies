#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        if(!n)return 0;
        int ans=0,x=n;
        while(x%5==0)
        {
            ans++;
            x/=5;
        }
        ans+=trailingZeroes(n-1);
        return ans;
    }
};