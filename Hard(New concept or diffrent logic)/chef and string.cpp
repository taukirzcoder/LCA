#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iterator>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll unsigned long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define mpll map<ll,ll>
#define  vpi vector<pair<int,int>>
#define f first
#define s second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ppb pop_back
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define fab(i,a,b) for(i=a;i<b;i++)
#define ln "\n"
//#define mod 1e9+7
ll mod = 1e9+7;
ll ans[100010], cnt[100010], cnt2[100010],fact[100010],inv[100010];
vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
ll bin_pow(ll o , ll s) {
    if(s==0)    return 1;
    else if(s==1)   return o%mod;
    ll d = bin_pow(o,s/2);
    d = (d*d)%mod;
    if(s%2==1)
        d=(d*o)%mod;
    return d;
}
ll c(ll n, ll k)
{
    ll res=1;
    res = (res*fact[n])%mod;
    res = (res*inv[k])%mod;
    res = (res*inv[n-k])%mod;
    return res;
}

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        ll n,q,i,j; string s;
        cin >> n >> q ; cin >> s;
        fact[0] = inv[0] = 1;
        ans[0]=0;
        for(i=1;i<=n;i++) {
            fact[i] = (fact[i-1]*i)%mod;
            inv[i] = bin_pow(fact[i],mod-2);
            ans[i] = 0;
            cnt2[i] = 0;
        }
        for(i=0;i<n;i++) {
            //cout << s.substr(i,n-i) << "  ";
            vector<ll> z = z_function(s.substr(i,n-i));
            for(j=0;j<=n;j++)   cnt[j]=0;
            for(auto x:z)   cnt[0]++ , cnt[x+1]--;
            for(j=1;j<=n;j++)   cnt[j]+=cnt[j-1] , cnt2[cnt[j]]++;
            ans[1] += n-i;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++) {
                ans[j+1] += (cnt2[i]*c(i,j))%mod;
                ans[j+1] %= mod;
            }
        }
        ll x;
        while(q--) {
            cin >> x;
            if(x > n)
                cout << 0 << ln;
            else 
                cout << ans[x] << ln;
        }
    }
    return 0;
}
