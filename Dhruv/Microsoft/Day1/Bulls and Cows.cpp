class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0; int y=0;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for (int i=0; i<guess.size(); i++){
            if (guess[i]== secret[i]){
                x++;
            }
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for (auto val: mp2){
            if (mp1.find(val.first) != mp1.end()){
                y+= min(val.second, mp1[val.first]);
            }
        }
        string a,b;
        if (x==0)a+='0';
        if (y==0)b+='0';
        while(x>0){
            a+= (x%10)+'0';
            x/= 10;
        }
        while (y>0){
            b+= (y%10)+'0';
            y/= 10;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        ans+=a;
        ans+= 'A';
        ans+=b;
        ans+='B';
        return ans;
    }
};