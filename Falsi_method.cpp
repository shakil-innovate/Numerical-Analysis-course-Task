//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'
const ll mod=1e9+7;
const ll INF=1e9;
#define vi vector<ll>
#define vii vector<vi>

ll add(ll a,ll b){ return ((a%mod + b%mod)+ mod ) % mod;}
ll sub(ll a,ll b){ return ((a%mod - b%mod)+mod)% mod;}
ll mul(ll a,ll b){ return ((a%mod) * (b%mod))%mod ;}
ll power(ll a, ll b){
    ll res=1;
    a%=mod;
        while(b > 0){
            if(b & 1)res=(res*a) %mod;
            a=(a*a)%mod;
            b=b>>1;
        }
    return res;
}
ll inv(ll a){return power(a,mod-2);}
//---------------------------------------//
db tolerance=.000001;

db calculateFunction(db x)
{
    return 4*x*x+3*x-3;
}

void bisection(db a,db b)
{
    db error=1e5;
    ll step=1;
    db mid=10;

    while(error>tolerance)
    {
         mid=(a*calculateFunction(b)-b*calculateFunction(a))/(calculateFunction(b)-calculateFunction(a));
        error=abs(a-b);

        db res=calculateFunction(a)*calculateFunction(mid);
        if(res<=0)
        {
            b=mid;
        }
        else a=mid;

        cout<<"step :"<<step<<" "<<"approximation value: "<<mid<<" Error:"<<error<<nl;
        step++;
    }

    cout<<"Final Result:"<<mid<<nl;
    
}

void shakil()
{
    cout<<"Enter Guess value:";
    db a,b; cin>>a>>b;
    bisection(a,b);
}
int  main()
{
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt=1;
    // cin>>tt;
  
    for(int i=1;i<=tt;i++)
    {
      shakil();
    }
}

