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

ld dif_eq(ld x,ll y){
  return (-2*x*x*x+12*x*x-20*x+8.5)*1.0;      // differential equation
}
void shakil(){
  ld a1=1.0/6.0,a2=2.0/6.0,a3=1.0/6.0, p1=1.0/2.0 , q11=1.0/2.0 , p2=1.0 , q21=-1.0, q22=2.0;
  ld h=.1;
  ld x=0,y=1;
  ld lm_x=4;

  ll step=1;
  while(x<lm_x){
    ld k1=dif_eq(x,y);
    ld k2=dif_eq(x+p1*h, y+q11*k1*h);
    ld k3=dif_eq(x+p2*h,y+q21*k1*h+ q22*k2*h);

    y=y+h*(a1*k1+a2*k2+a3*k3);
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
