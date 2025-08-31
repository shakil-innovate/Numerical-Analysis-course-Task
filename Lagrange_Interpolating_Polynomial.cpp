//*********************************************//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef double db;
#define nl '\n'
const ll INF=1e9;
//********************************************************//

struct State
{
   db x,y;
};
void lagrange()
{
   cout<<"Input Total point:"<<nl;
   ll n; cin>>n;

   vector<State>point;
   for(int i=0;i<n;i++)
   {
      db x,y;  cin>>x>>y;
      point.push_back({x,y});
   }
   cout<<"Enter the x that you want for this to y :"<<nl;
   db x; cin>>x;

   db tlt=0;
   for(ll i=0;i<n;i++)
   {
      db temp=1;
      for(ll j=0;j<n;j++)
      {
         if(i==j)continue;
         else
         {
            temp*=(x-point[j].x)*1.0;
            temp/=(point[i].x-point[j].x)*1.0;
         }

      }
      temp*=point[i].y;
      tlt+=temp;
   }

   cout<<"Value y for "<<x<<" is: "<<tlt<<nl;
}

int  main()
{
   lagrange();
}
