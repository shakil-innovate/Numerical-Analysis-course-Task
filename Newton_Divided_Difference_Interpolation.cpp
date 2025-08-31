//*********************************************//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'
#define f first
#define s second
const ll INF=1e9;
//********************************************************//

struct State
{
   db age,pore;
};

void newton_divided_difference()
{
   cout<<"Enter the total Point number:"<<nl;
   ll n; cin>>n;

   cout<<"Enter all point"<<nl;
   vector<pair<State,db>>point,real_point;

   for(int i=0;i<n;i++)
   {
      db x,y;  cin>>x>>y;
      point.push_back({{x,x},y});
   }
   real_point=point;
   vector<db>difference(100000);
   difference[0]=point[0].s;

   ll cnt=1;
         while(point.size()>1)
         {
            vector<pair<State,db>>new_point;
            ll temp_cnt=1;
            for(ll i=1;i<point.size();i++)
            {
               db tempY=1.0*(point[i].s-point[i-1].s)/(point[i].f.pore-point[i-1].f.age);
               db fAge=point[i-1].f.age;
               db fPore=point[i].f.pore;
               new_point.push_back({{fAge,fPore},tempY});
               if(temp_cnt==1)difference[cnt]=tempY;
               temp_cnt++;
            }
            point=move(new_point);
            cnt++;
         }

         cout<<"Enter x that you want to y:"<<nl;
         db x; cin>>x;

         db ans=0;
         for(ll i=0;i<n;i++)
         {
            db temp=difference[i];
            for(ll j=i-1;j>=0;j--)
            {
               temp*=1.0*(x - real_point[j].f.age);
            }
            ans+=temp;
         }

      cout<<ans<<nl;

}

int  main()
{
   newton_divided_difference();
}
