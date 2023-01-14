class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        vector<int>s(10,0);
        vector<int>g(10,0);
        int B=0;
        int C=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                B++;
            }
            else{
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            C+=min(s[i],g[i]);
        }
        string result="";
        result+=to_string(B);
        result+='A';
          result+=to_string(C);
        result+='B';

        return result;

    }
};
