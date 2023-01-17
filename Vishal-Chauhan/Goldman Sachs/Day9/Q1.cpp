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

    mySet[1 + delay] = 1 + forget;
    i++;
    while (mySet.size() > 0 && i <= n)
    {
    jump:
        map<ll, ll>::iterator it = mySet.begin();
        for (; it != mySet.end(); it++)
        {
            if (i <= n)
            {
            jump2:
                int knowDay = it->first;
                int forgetDay = it->second;
                // cout<<"\n  i:"<<i<<" ";cout<<" | k:"<<knowDay<<"  fd:"<<forgetDay;
                if (i >= knowDay && i < forgetDay)
                {
                    // cout<<"  ii:"<<i<<" ";
                    // cout<<" | k:"<<knowDay<<"  fd:"<<forgetDay<<"  and inserted:"<<i + delay<<" ->"<<i+forget<<endl;
                    mySet[i + delay] = i + forget;
                    it++;
                    // if(it!=mySet.end()) goto jump2;
                    // else
                    i++;
                    goto jump;
                }
                else
                {
                    it++;
                    if ((it) != mySet.end())
                        goto jump2;
                }

                i++;
            }
        }
    }
    return mySet.size();
}

// method2
#define MOD 1000000007;
int peopleAwareOfSecret2(int n, int delay, int forget)
{
    ll i = 2;
    vector<vector<ll>> person = {{1 + delay, 1 + forget, 1}}; // startOfSpread,forgetDay,countOfPpl
    while (i <= n)
    {
        while (!person.empty() && person[0][1] == i)
        {
            person.erase(person.begin());
        }
        ll cnt = 0;
        for (auto val : person)
        {
            if (val[0] <= i)
            {
                cnt += val[2];
            }
            cnt %= MOD;
        }
        person.push_back({i + delay, i + forget, cnt});
        i++;
    }
    ll ans = 0;
    for (auto val : person)
    {
        ans += val[2];
        ans %= MOD;
    }
    return ans;
}

int main()
{
    int n = 6, delay = 2, forget = 4;
    cout << peopleAwareOfSecret2(n, delay, forget);
    // string str = "452";
    // cout << stoi(str) + 8 << endl;
}