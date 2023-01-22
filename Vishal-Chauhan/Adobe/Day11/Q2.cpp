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
string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return "0";
    if (denominator == 0)
        return "";

    string res;
    if ((numerator < 0) ^ (denominator < 0))
        res += "-";

    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);

    res += to_string(num / den);
    long long remainder = num % den;
    if (remainder == 0)
        return res;

    res += ".";
    unordered_map<long long, int> map;
    while (remainder != 0)
    {
        if (map.count(remainder) > 0)
        {
            res.insert(map[remainder], "(");
            res += ")";
            break;
        }
        map[remainder] = res.size();
        remainder *= 10;
        res += to_string(remainder / den);
        remainder %= den;
    }

    return res;
}
int main()
{
    cout << "ans:" << fractionToDecimal(23, 6) << endl;
    cout << "ans:" << fractionToDecimal(27, 6) << endl;
    cout << "ans:" << fractionToDecimal(4, 6) << endl;
}