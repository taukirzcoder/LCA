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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
#define ln "\n"
int main() {
    fastio
    int i,j,n,x;
    string s;
    cin >> s;
    n=s.size();
    vector<int> z= z_function(s);   //cout << z.size();;
    vector<int> vec=z;
    sort(vec.begin(),vec.end());
    vpi ans; pair<int,int> p;
    for(i=0;i<n;i++) {
        if(z[n-i-1] == i+1) {
            ll x= (vec.end()-lb(vec.begin(),vec.end(),i+1))+1;
            ans.pb({i+1,x});
        }
    }
    ans.pb({n,1});
    cout << ans.size() << ln;
    for(i=0;i<ans.size();i++)        cout << ans[i].f << " " << ans[i].s << "\n";
    return 0;
}
