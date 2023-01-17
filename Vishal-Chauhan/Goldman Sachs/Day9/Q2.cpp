#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
#define ll long long int
#define inf 11111111111
using namespace std;
#define ll long long
vector<string> invalidTransactions(vector<string> &tra)
{
    set<string> st;
    set<string> stt;
    vector<string> output;
    ll ans = 0;
    for (auto val : tra)
    {
        stringstream ss(val);

        while (ss.good())
        {
            string substr = "1";
            string substr2 = "1";
            getline(ss, substr, ',');
            getline(ss, substr2, ',');
            if (st.find(substr) == st.end())
            {
                cout << "not founded:" << substr << " -->";
                st.insert(substr);
                stt.insert(val);
                break;
                cout << "break";
            }
            else
            {
                cout << "inside else\n";

                string value;
                for (auto strr : stt)
                {
                    stringstream ssss(val);
                    string su = "1";
                    string su2 = "1";
                    getline(ssss, su, ',');
                    getline(ssss, su2, ',');
                    if (su == substr)
                    {
                        value = strr;
                        break;
                    }
                }

                auto itr = stt.find(value);
                // if(itr==stt.end())
                // cout<<"overrrrrrrrrrr\n";
                cout << "sssttt:" << *itr << " ";
                ll tame = stoi(substr2);
                cout << "after for loop\n";

                stringstream sss(*itr);
                string sub1, sub2;
                getline(sss, sub1, ',');
                getline(sss, sub2, ',');

                ll tam2 = stoi(sub2);
                cout << "t1:" << substr2 << " tam2:" << sub2 << endl;
                if (tame + 60 >= tam2)
                {
                    // ans++;
                    output.push_back(val);
                }
            }
        }
    }
    cout << "ans:" << ans << endl;
    return output;
}

int main()
{
}