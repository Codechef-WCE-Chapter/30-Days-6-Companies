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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;
        int cnt = 0;
        for(auto &i : rectangles){
            m[{i[0], i[1]}]++;
            m[{i[2], i[3]}]++;
            m[{i[0], i[3]}]--;
            m[{i[2], i[1]}]--;
        }
        for(auto &i : m)cnt += abs(i.second);
        return cnt == 4;
    }
};