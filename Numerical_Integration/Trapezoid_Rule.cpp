//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;     typedef double db;
typedef long double ld;

#define pb push_back 
#define nl '\n'
#define vi vector<ll>
#define vii vector<vi>
#define f first
#define s second
const ll mod=998244353;      const ll INF=1e15;

ll add(ll a,ll b){ return ((a%mod + b%mod)+ mod ) % mod;}
ll sub(ll a,ll b){ return ((a%mod - b%mod)+mod)% mod;}
ll mul(ll a,ll b){ return ((a%mod) * (b%mod))%mod ;}
ll power(ll a, ll b){ll res=1; a%=mod;while(b > 0){if(b & 1)res=(res*a) %mod; a=(a*a)%mod;b=b>>1;}return res;}
ll inv(ll a){return power(a,mod-2);}

ll nCr(ll n, ll r) {
    if (r >n - r) r = n - r;
    ll res = 1;
    for (ll i = 0; i < r; ++i) {
        res = ((res * (n - i))%mod * inv (i + 1))%mod;
    }
    return res;
}
//---------------------------------------//

ld eq(ld x){
  return x*x*x-2*x*x+x+1;     // equation
}

void shakil(){
  ld a=0,b=2.0;
  ld n=10.0;
  ld h=(b-a)/n;

  ld sum=eq(a)+eq(b);
  
  a+=h;
  while(a<b){
    sum+=2*eq(a);
    a+=h;
  }

  ld ans=sum/2.0*h;

  cout<<fixed<<setprecision(15)<<ans<<nl;

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll tt=1; 
    // cin >> tt;
    for(ll i = 1; i <= tt; i++){
        shakil();
    }
    return 0;
}
