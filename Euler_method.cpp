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
    if (r > n - r) r = n - r;
    ll res = 1;
    for (ll i = 0; i < r; ++i) {
        res = ((res * (n - i))%mod * inv (i + 1))%mod;
    }
    return res;
}
//---------------------------------------//

ld dif_eq(ld x){
  return -2*x*x*x+12*x*x-20*x+8.5;      // differential equation
}
void shakil(){
  ld h=.5;
  ld x=0,y=1;
  ld lm_x=4;

  ll step=1;
  while(x<lm_x){
    y=y+h*dif_eq(x);
    x+=h;
  }
  cout<<"value of y at x is: "<<y<<nl;
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
