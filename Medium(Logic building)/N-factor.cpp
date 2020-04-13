#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     ll          long long int 

#define     pb         push_back
#define     ppb         pop_back
#define MAXN 1000005
#define mod 1000000007
ll spf[MAXN];
ll momo[11][1000005];
// SPF= Smallest Prime Factor
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
  
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
vector<ll> getFactorization(ll x) 
{ 
    vector<ll> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        ll temp = spf[x];
        while(x%temp == 0)
            x = x / temp; 
    } 
    return ret; 
} 
ll factor[1000005];
int main() 
{
    fastio
    sieve();
    factor[0]=factor[1]=0;
    for(ll i=0;i<11;i++)
    {
        momo[i][0]=0 , momo[i][1]=0;
    }
    for(ll i=2;i<1000005;i++)
    {
        vector<ll> v = getFactorization(i);
        factor[i] = v.size();
    }
    for(ll i=1;i<=10;i++)
    {
        ll var=i;
        for(ll j=2;j<1000005;j++)
        {
            momo[var][j] = momo[var][j-1];
            if(factor[j] == var)
            {
                momo[var][j]+=1;
            }
        }
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll a,b,n;
        cin >> a >> b >> n;
        if(n==0 && a==1)
        {
            cout << "1\n";
        }
        else if(n==0 && a>1)
        {
            cout << "0\n";
        }
        else {
            ll ans= momo[n][b]-momo[n][a-1];
            cout << ans << "\n";
        }
    } 
    return 0;
}
