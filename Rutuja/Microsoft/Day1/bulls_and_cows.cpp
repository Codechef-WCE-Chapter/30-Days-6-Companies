/*Bulls and Cows: https://leetcode.com/problems/bulls-and-cows/  */

#include<bits/stdc++.h>
using namespace std;

//Note: maps


// Approach 1: Use of maps
// T.C: O(n)
// S.C: linear -> map

class Solution {
public:
    string getHint(string secret, string guess) {
        int num=0, flag=0, bull=0, cow=0;
        unordered_map<char, int> gmap;
        unordered_map<char, int> smap;

        string ans="";
        for(int i=0; i<secret.length(); i++)
        {
            if(secret[i]==guess[i])
            bull++;
            else
            {
                gmap[secret[i]]++;
                smap[guess[i]]++;
            }
           
        }

        for(int i=0; i<gmap.size(); i++)
        {
            cow+= min(gmap[i], smap[i]);
        }
        stringstream s;
        s << bull << "A" << cow << "B" ;
        ans = s.str();
        
        return ans;
    }
};