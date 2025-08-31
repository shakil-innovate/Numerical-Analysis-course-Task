//*********************************************//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef double db;
#define nl '\n'
const ll INF=1e9;
//********************************************************//

const db tolerance=1e-3;

db f(db x)
{
   return x*x*x*x*x+3*x+5;
}
db dif_f(db x)
{
   return 5*x*x*x*x+3;
}

db res(db x)
{
   return 1.0*(x-f(x)/dif_f(x));
}

void Newton_Raphson(db a)
{
  db prev_x=res(a);
  db x;

  db error=INF*1.0;
  ll step=0;
  cout<<"Step:    "<<"error"<<nl;

  while(error>tolerance)
  {
      x=res(prev_x);
      error=fabs(x-prev_x);
      step++;
      prev_x=x;

      cout<<step<<"   "<<x<<"     "<<error<<nl;
      if(fabs(f(prev_x))<tolerance)break;
  }
  cout<<"Root is: "<<prev_x<<nl;
  
}

int  main()
{
   cout<<"Enter guessing one val:"<<nl;
   db a;  cin>>a;
   Newton_Raphson(a);
}
