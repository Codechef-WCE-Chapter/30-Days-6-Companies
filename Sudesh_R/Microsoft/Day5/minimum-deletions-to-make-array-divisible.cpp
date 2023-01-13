class Solution {
public:
    int minOperations(vector<int>& v, vector<int>& d) {
        int n = v.size();
        int gcd = d[0];
        for(int i = 1;i<d.size();i++)
        {
            gcd = __gcd(gcd , d[i]);
        }
        cout<<gcd<<endl;
        priority_queue<int , vector<int> , greater<int>>pq;
        for(int i  =0 ;i<n;i++)
        {
            pq.push(v[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();

            if(gcd%x==0)
            {
                return ans;
            }
            ans++;
        }
        return -1;
    }
};
