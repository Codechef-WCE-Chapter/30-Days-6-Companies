class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        map<char,int>m;
        map<char,int>n;
        for(int i = 0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                m[secret[i]]++;
                n[guess[i]]++;
            }
        }
        for(auto it:m){
            if(n.find(it.first)!=n.end()){
                cows+=min(it.second,n[it.first]);
            }
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};