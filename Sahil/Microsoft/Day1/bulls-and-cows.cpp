class Solution {
public:
    string getHint(string secret, string guess) {
        int x =0,y=0;
        int n = secret.length();
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                x++;
            }
        }
        
        vector<int> mp1(10,0),mp2(10,0);
        for(int i=0;i<n;i++){
            mp1[secret[i] - '0']++;
        }
        for(int i=0;i<n;i++){
            mp2[guess[i] - '0']++;
        }
        
        for(int i=0;i<10;i++){
            y += min(mp1[i],mp2[i]);
        }
        
        return to_string(x) + 'A' + to_string(y-x) + 'B';
    }
};