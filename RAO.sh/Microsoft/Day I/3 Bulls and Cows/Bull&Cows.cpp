class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        vector<int> freq(10, 0);
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                if(freq[secret[i] - '0']++ < 0) cows++;
                if(freq[guess[i] - '0']-- > 0) cows++;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
