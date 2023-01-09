//https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
     string ans;
     map<char,int> mp;
     int bulls=0,cows=0;
     for(int i = 0;i<secret.size();i++){
         if(secret[i]==guess[i]) bulls++;
         mp[secret[i]]++;
     }
     for(int i = 0;i<guess.size();i++){
         if(mp[guess[i]]){
             cows++;
            mp[guess[i]]--;
         } 
     }
     cows-=bulls;
     ans = to_string(bulls)+"A"+to_string(cows)+"B";
    return ans;
    }
};
