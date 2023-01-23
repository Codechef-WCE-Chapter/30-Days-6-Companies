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
using namespace std;
class StockPrice
{
public:
    map<int, int> mp;
    multiset<int> mset;
    int time = 0;
    int curr = 0;
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        if (timestamp >= time)
        {
            curr = price;
            time = timestamp;
        }
        if (mp.find(timestamp) == mp.end())
        {
            mp.insert({timestamp, price});
            mset.insert(price);
        }
        else
        {
            auto it = mset.find(mp[timestamp]);
            mset.erase(it);
            mp[timestamp] = price;
            mset.insert(price);
        }
    }

    int current()
    {
        return curr;
    }

    int maximum()
    {
        // return maxheap.top();
        return *(mset.rbegin());
    }

    int minimum()
    {
        // return minheap.top();
        return *(mset.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

int main()
{
}