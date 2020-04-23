#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()

#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);   cout.tie(NULL);
    string s; cin >> s;
    int count[2];
    count[0]=count[1]=0;
    int lp=-1,i;
    char cur='R';
    int n=s.size();
    int ans[n]={0};
    for(i=0;i<n;i++)
    {
        if(s[i]==cur)
        {
            count[i%2]++;
        }
        else{
            if(s[i]=='L')
            {
                lp=i-1;
                ans[lp]+=count[lp%2];
                ans[lp+1]+=count[(lp+1)%2];
            }
            else {
                ans[lp]+=count[lp%2];
                ans[lp+1]+=count[(lp+1)%2];
            }
            count[0]=count[1]=0;
            count[i%2]++;
            cur=s[i];
        }
    }
    ans[lp]+=count[lp%2];
    ans[lp+1]+=count[(lp+1)%2];
    for(i=0;i<n;i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
