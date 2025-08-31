//*********************************************//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef double db;
#define nl '\n'
//********************************************************//

const db tolerance=1e-6;

db func(db x)
{
   return 4*x*x+3*x-3;
}

void bisection(db a,db b)
{
   db mid=(a+b)/2;
   db error=fabs(a-b);

   ll step=0;
   cout<<"Step: "<<"a       "<<"b     "<<"error"<<nl;
   while(error>tolerance)
   {
      mid=(a+b)/2;
      if(func(a)*func(mid)<=0)
      {
         b=mid;
      }
      else a=mid;
      error=fabs(a-b);
      step++;
   cout<<step<<"     "<<a<<"      "<<b<<"  "<<error<<nl;

   }
   cout<<"Root is"<<mid<<nl;
}

int  main()
{
   cout<<func(.75)<<" "<<func(1)<<nl;
   cout<<"Enter guessing two val:"<<nl;
   db a,b;  cin>>a>>b;
   bisection(a,b);
}
