#define ll long long ll

class Solution 
{
public:
    string getHll(string secret, string guess) 
    {
        ll ct1=0;
        ll ct2=0;

        vector<ll>secretTable(10,0);
        vector<ll>guessTable(10,0);

        for(ll i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i]) 
            {
                ct1++;
            }
            else
            {
                secretTable[secret[i]-'0']++;
                guessTable[guess[i]-'0']++;
            }
        }

        for(ll i=0;i<10;i++)
        {
            ct2+=min(secretTable[i],guessTable[i]);
        }

        string sp=to_string(ct1)+'A'+to_string(ct2)+'B';

        return  sp;
    }
};

