//*********************************************//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef double db;
#define nl '\n'
const ll INF=1e9;
//********************************************************//

const db tolerance=1e-10;

db f(db x)
{
   return (1.0*log(3*x)-3);
}

db res(db a,db b)
{
   return (b*f(a)-a*f(b))/(f(a)-f(b))*1.0;
}

void regular_falsi(db a,db b)
{
  db prev_c=INF*1.0;
  db c=res(a,b);

   ll step=0;
   cout<<"Step: "<<"a       "<<"b     c      "<<"error"<<nl;
   db error=INF*1.0;

   while(error>tolerance)
   {
      c=res(a,b);
      if(f(a)*f(c)<=0)
      {
         b=c;
      }
      else a=c;
      error=fabs(prev_c-c);
      prev_c=c;
      step++;
      cout<<step<<"   "<<a<<"     "<<b<<"    "<<c<<"     "<<error<<nl;
      if(fabs(f(c))<=tolerance)break;
      
   }
   cout<<"Root is: "<<prev_c<<nl;
}

int  main()
{
   cout<<"Enter guessing two val:"<<nl;
   db a,b;  cin>>a>>b;
   regular_falsi(a,b);
}
