#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
// using namespace std;not getting correct ouput for all case /////////////
//
int findIntegers(int n)
{
    int dp[32] = {0};
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= 31; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int ans = 0, lastBit = -1;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit)
        {
            if (lastBit == -1)
            {
                ans += dp[i];
            }
            else
            {
                ans += dp[i + 1];
            }
            lastBit = 1;
        }
        else
        {
            lastBit = 0;
        }
    }
    if (lastBit == -1)
    {
        ans++;
    }
    return ans;
}

int main()
{
    cout << findIntegers(9) << endl;
}