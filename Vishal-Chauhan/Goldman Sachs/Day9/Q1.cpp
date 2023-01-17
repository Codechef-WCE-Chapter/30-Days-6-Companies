#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
#define inf 11111111111
using namespace std;
// method1
int peopleAwareOfSecret(int n, int delay, int forget)
{
    map<ll, ll> mySet;
    int i = 1;

    // unordered_set<vector<int>> mySet;

    // mySet.insert({1+delay,1+forget});
    mySet[1 + delay] = 1 + forget;
    i++;
    while (mySet.size() > 0 && i <= n)
    {
        for (auto val : mySet)
        {
            if (i <= n)
            {
                int knowDay = val.first;
                int forgetDay = val.second;
                if (i >= knowDay && i < forgetDay)
                {
                    mySet[i + delay] = i + forget;
                }
                i++;
            }
            else
                break;
        }
        // i++;
    }
    return mySet.size();
}