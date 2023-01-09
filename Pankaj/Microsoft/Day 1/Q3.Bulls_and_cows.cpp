//Microsoft: Q3. Bulls and Cows
class Solution {
public:
    string getHint(string secret, string guess) {
        int n=guess.size();
        int digit[10]={0};
        for(auto i:secret) digit[i-'0']++;
        int bulls=0;
        int cows=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
                digit[secret[i]-'0']--;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]&&digit[guess[i]-'0']){
                cows++;
                digit[guess[i]-'0']--;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};