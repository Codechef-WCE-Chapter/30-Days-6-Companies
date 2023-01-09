class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        for(int i=0;i<secret.size();i++){
            m1[secret[i]]++;
        }

        for(int i=0;i<guess.size();i++){
            m2[guess[i]]++;
        }

        int bulls=0,cows=0;
        for(int i=0;i<guess.size();i++){
            if(guess[i]==secret[i]){
                bulls++;
                m1[secret[i]]--;
                m2[guess[i]]--;
            }
        }

        for(int i=0;i<guess.size();i++){
            if(guess[i]!=secret[i]){
                if(m2[guess[i]]!=0 && m1.find(guess[i])!=m1.end() && m1[guess[i]]!=0){
                    cows++;
                    m1[guess[i]]--;
                    m2[guess[i]]--;
                }
            }
        }

        string ans="";
        ans+=to_string(bulls);
        ans+="A";
        ans+=to_string(cows);
        ans+="B";
        return ans;
    }
};