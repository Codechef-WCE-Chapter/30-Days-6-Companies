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
    string getHint(string secret, string guess) {
        map<int,int>m;
        int bulls=0,cows=0;
        for(int i = 0; i < guess.size(); ++i){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                if(m[secret[i]-'0']++ < 0) cows++;
                if(m[guess[i]-'0']-- > 0) cows++;
            }
        }
        string fans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return fans;
    }
};