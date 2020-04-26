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
string t, p;
ll a[200005],n,m;
bool check(ll mid)   // check whether a given string is present in mid no of elments are removed as directed by array a
{
    string temp;
    temp= t;
    ll j=0,i=0;
    for(i=0;i<mid;i++)  temp[a[i]]='$';   //removing mid no of elements as directed by array a
    for(i=0;i<n && j<m ; i++)
        if(temp[i] == p[j])
            j++;
    return j==m;  //return ture if p is present in text after removing mid no of elements
}

int main() {
    fastio
    cin >> t >> p;
    ll l,r,mid,i,j,ans=-1; n=t.size(); m=p.size();
    for(i=0;i<n;i++)    cin >> a[i] , a[i]-=1;
    l=0;r=n-1;
    while(l<=r) {
        mid = l+(r-l)/2;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        }
        else    r=mid-1;
    }
    cout << ans;
    return 0;
}
