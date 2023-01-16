class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double a=sqrt(pow((p2[0]-p1[0]),2)+pow((p2[1]-p1[1]),2));
        
        double b=sqrt(pow((p3[0]-p2[0]),2)+pow((p3[1]-p2[1]),2));

        double c=sqrt(pow((p4[0]-p3[0]),2)+pow((p4[1]-p3[1]),2));

        double d=sqrt(pow((p1[0]-p4[0]),2)+pow((p1[1]-p4[1]),2));

// cout<<a<<b<<c<<d<<endl;

        
           double d1=sqrt(pow((p3[0]-p1[0]),2)+pow((p3[1]-p1[1]),2));
           double d2=sqrt(pow((p4[0]-p2[0]),2)+pow((p4[1]-p2[1]),2));
        //    cout<<d1<<" "<<d2;

map<double,int>mp;
mp[a]++;
mp[b]++;
mp[c]++;
mp[d]++;
mp[d1]++;
mp[d2]++;
bool sid=false,dig=false;
for(auto m:mp)
{
   if(m.second==4)
   {
       sid=true;
   }
   cout<<m.first<<" "<<m.second<<endl;
   if(m.second==2)
   {
       dig=true;
   }
}

if(p2==p4 and p3==p1)
return false;
if(sid and dig)
{return true;}






        //    if(a==b && b==c && c==d && d==a && d==b && c==a && d1==d2 )
        //    {
        //        return true;
        //    }
           return false;
    }
};
