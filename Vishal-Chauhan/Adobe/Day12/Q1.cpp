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
int magicalString(int n)
{
    string s = "122";
    int i = 2;
    while (s.size() < n)
    {
        s += string(s[i++] - '0', (s.back() == '1') ? '2' : '1');
    }
    return count(s.begin(), s.begin() + n, '1');
}

int main()
{
    cout << magicalString(8) << endl;
    cout << magicalString(3) << endl;
}