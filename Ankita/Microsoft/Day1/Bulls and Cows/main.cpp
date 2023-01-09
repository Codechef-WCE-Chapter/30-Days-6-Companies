#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        string s1 = secret;
        string s2 = guess;
        //x->no of cows y->no of bulls
        int x=0;
        int y=0;
        //creating hash of no of occurance of each char
        unordered_map<char, int> secret_map;
        unordered_map<char, int> guess_map;

        for(int i=0; i<secret.size(); i++){
            secret_map[secret[i]]++;
        }
        for(int i=0; i<guess.size(); i++){
            guess_map[guess[i]]++;
        }
        for(auto &it: secret_map){
            if(guess.find(it.first)>=0){
                int val = min(it.second, guess_map[it.first]);
                y+=val; //storing no of common character
            }
        }
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]){
                x++; //storing no of character having same position
            }
        }

        y = y-x; // find no of bulls
        string ans = to_string(x);
        ans+=+"A";
        ans+=to_string(y);
        ans+="B";

        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.getHint("1123", "0111");
}