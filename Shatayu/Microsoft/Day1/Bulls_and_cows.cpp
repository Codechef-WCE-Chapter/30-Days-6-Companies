class Solution {
public:
    string getHint(string secret, string guess) {
        int count=0;
        int cnt = 0;
        map<int,int> m1;
        map<int,int> m2;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                count++;
            }
            else{
                m1[secret[i]-'0']++;
                m2[guess[i]-'0']++;
            }
        }
        for(auto i: m1){
            if(m2.find(i.first)!=m2.end()){
                cnt+=min(m2[i.first], i.second);
            }
        }
        string ans="";
        ans = to_string(count) + "A" + to_string(cnt) + "B";
        return ans;
    }
};