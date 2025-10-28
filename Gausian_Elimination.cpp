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
void shakil(){
  ll n=3;
  vector<vector<ld>>matrix(4,vector<ld>(5));

  for(ll i=1;i<=3;i++){
    for(ll j=1;j<=4;j++){
      cin>>matrix[i][j];
    }
  }

  for(ll i=1;i<=3;i++){
      for(ll next_r=i+1;next_r<=3;next_r++){
        if(fabs((matrix[next_r][i])>fabs(matrix[i][i]))){
          swap(matrix[next_r],matrix[i]);
        }
      }

      for(ll row=1;row<=3;row++){
        if(row==i)continue;

        ld mul=matrix[row][i];
        for(ll col=i;col<=4;col++){
          matrix[row][col]=(matrix[row][col])-((matrix[i][col]*mul*1.0)/(matrix[i][i]*1.0));
        }
      }
  }

  for(ll row=1;row<=3;row++){
    matrix[row][4]/=matrix[row][row];
    matrix[row][row]=1;
  }

  cout<<"solution is below: "<<nl;
  for(ll i=1;i<=3;i++)cout<<fixed<<setprecision(15)<<matrix[i][4]<<nl;
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
