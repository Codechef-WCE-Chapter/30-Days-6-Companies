class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0,cows=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bull++;
                secret[i]=-1;
                guess[i]=-1;
            }
        }
        map<char,int> mp;

        for(int i=0;i<secret.length();i++){
            mp[secret[i]]++;
        }
       
       for(int i=0;i<guess.length();i++){
           if(guess[i]!=secret[i]&&mp[guess[i]]>0){
               cows++;
               mp[guess[i]]--;
           }
       }

     return to_string(bull) + "A" + to_string(cows) +"B";
    }
};
