///*राधे कृष्णा*///

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
#define ln "\n"
// B-Password
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

int main() {
    fastio
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    int n=z.size(),i; int maxin=-1,j;
    //f0(i,n) cout << z[i] << " ";
    vector<int> v=z; vpi ans; //vector<string> vs;
    sort(v.begin(),v.end()); 
    for(i=0;i<n;i++) {
        if(z[n-i-1] == (i+1)) {
            ll x = (v.end()- lb(v.begin(),v.end(),(i+1))) + 1;
            //cout << ln << x;
            ans.pb({n-i-1, x});
        }
    }
    bool f=0;
    int sz= ans.size();
    for(i= sz-1 ; i>=0;i--) {
        if(ans[i].s >= 3) {
            for(j=ans[i].f;j<n;j++)    cout << s[j];
            f=1;
            break;
        }
    }
    if(f==0)    cout<< "Just a legend";
    return 0;
}
