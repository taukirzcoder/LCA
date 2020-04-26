#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
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
ll a[50005],n,k;
bool check(ll mid)
{
    ll i=0,sum=0,cnt=0; ll ans=k*mid;
    for(i=0;i<n;i++) {
        cnt+=((a[i])/mid);
        if(cnt >= k)  return true;
    }
    return false;
}

int main() {
    fastio
    int t;
    cin >> t;
    while(t--) {
        ll i,j,x,y,sum=0;
        for(i=0;i<50005;i++)    a[i]=0;
        cin >> n >> k; 
        for(i=0;i<n;i++)    cin >> a[i] , sum+=a[i];
        sort(a,a+n,greater<ll>());
        //for(i=0;i<n;i++)    cout << a[i] << " ";
        if(k > sum) cout << 0 << ln;
        else {
            ll l=1 , r=sum/k , mid , ans;
            while(l<=r) {
                ll mid = l+(r-l)/2;
                if(check(mid)) {
                    ans=mid;
                    l=mid+1;
                }
                else    r=mid-1;
            }
            cout << ans << ln;
        } 
    }
    return 0;
}
