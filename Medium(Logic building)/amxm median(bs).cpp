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
#define ll long long 
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
ll n,k,i,j;
vll a;
ll mod = 1e9+7;
bool check(ll x ) {
    ll moves=0;
    for(i=n/2;i<n;i++)
    {
        if(x-a[i] > 0)  moves+=(x-a[i]);
        if(moves > k)   return false;
    }
    if(moves <= k)  return true;
    else    return false;
}
int main() {
    fastio
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     #endif*/
    ll x,ans;
    cin >> n >> k;
    f0(i,n) cin >> x , a.pb(x);
    sort(a.begin() , a.end());
    ll ind=n/2;
    ll l=a[ind],r=2e9+10;
    ll mid;
    while(l<=r) {
        mid=l+(r-l)/2;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}
