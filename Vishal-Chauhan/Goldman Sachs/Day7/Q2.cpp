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

// -------meth1------
bool isPossible(vector<int> &nums)
{
    map<int, int> mp;
    for (auto val : nums)
    {
        mp[val]++;
    }
    int a = 0, b = 0;
    int flag_got_2 = 0;
    for (auto val : mp)
    {
        if (val.second == 1 && flag_got_2 == 0)
        {
            a++;
        }
        else if (val.second == 2)
        {
            flag_got_2++;
            b++;
            a++;
        }
        else
            b++;
    }
    cout << "a:" << a << " b:" << b << endl;
    if (a == 3 || a >= 6 || (a >= 3 && b >= 3))
        return true;
    else
        return false;
}

// ---meth2---
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> ss1, ss2;
        for (int val : nums)
        {
            if (ss1.size() < 3)
            {
                if (ss1.find(val) == ss1.end())
                {
                    ss1[val]++;
                }
                else if (ss2.find(val) == ss2.end())
                {
                    ss2[val]++;
                }
                else
                    return false;
            }
            else
            {
                if (ss2.size() < 3)
                {
                    if (ss2.find(val) == ss2.end())
                    {
                        ss2[val]++;
                    }
                    else if (ss1.find(val) == ss1.end())
                    {
                        ss1[val]++;
                    }
                    else
                        return false;
                }
                else
                {
                    if (ss2.find(val) == ss2.end())
                    {
                        ss2[val]++;
                    }
                    else if (ss1.find(val) == ss1.end())
                    {
                        ss1[val]++;
                    }
                    else
                        return false;
                }
            }
        }
        if (ss1.size() >= 3 && ss2.size() >= 3)
            return true;
        else
            return false;
    }
};
// --------------meth3
bool isPossible3(vector<int> &nums)
{
    map<int, int> ss1, ss2;
    int n = nums.size();
    for (int val : nums)
    {
        if (ss1.size() < 3)
        {
            if (ss1.find(val) == ss1.end())
            {
                ss1[val]++;
            }
            else if (ss2.find(val) == ss2.end())
            {
                ss2[val]++;
            }
            else
                return false;
        }
        else
        {
            if (ss2.size() < 3)
            {
                if (ss2.find(val) == ss2.end())
                {
                    ss2[val]++;
                }
                else if (ss1.find(val) == ss1.end())
                {
                    ss1[val]++;
                }
                else
                    return false;
            }
            else
            {
                if (ss2.find(val) == ss2.end())
                {
                    ss2[val]++;
                }
                else if (ss1.find(val) == ss1.end())
                {
                    ss1[val]++;
                }
                else
                    return false;
            }
        }
    }
    if ((ss1.size() >= 3 && ss2.size() >= 3) || (ss1.size() == 3 && ss2.size() == 0) || ss2.size() == 3 && ss1.size() == 0)
    {
        int temp1 = 0, temp2 = 0;
        int c1 = 0, c2 = 0;
        for (auto val : ss1)
        {
            if (temp1 == 0)
            {
                temp1 = val.first;
                c1++;
            }
            else
            {
                if (temp1 + 1 == val.first)
                {
                    temp1 = val.first;
                    c1++;
                    continue;
                }
                else
                {
                    if (c1 < 3)
                        return false;
                }
            }
        }
        for (auto val : ss2)
        {
            if (temp2 == 0)
            {
                temp2 = val.first;
                c2++;
            }
            else
            {
                if (temp2 + 1 == val.first)
                {
                    temp2 = val.first;
                    c2++;
                    continue;
                }
                else
                {
                    if (c2 < 3)
                        return false;
                }
            }
        }
        if (c1 + c2 == n)
            return true;
    }
    return false;
}
// --------------------meth4
int main()
{
}