#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     ll          long long int 
#define     pb         push_back
#define     ppb         pop_back
#define mod 1000000007
ll fact[1000006]={0};
ll modpow(ll x , ll pow )
{
    ll ans=1;
    while(pow > 0)
    {
        if(pow%2 == 1)
        {
            ans = (ans*x)%(mod);
        }
        x = (x*x)%(mod) ;
        pow = pow/2;
    }
    return ans;
}
long long binpow(long long val, long long deg, long long modulo) {
        if (!deg) return 1 % modulo;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % modulo;
        long long res = binpow(val ,deg >> 1, modulo);
        return (res*res) % modulo;
}
void fillFact()
{
    ll i;
    fact[0]=1;
    for(i=1;i<1000006;i++)
    {
        fact[i]= (fact[i-1]*i)% mod;
    }
}
bool check(ll n, ll a, ll b)
{
    while(n>0)
    {
        if(n%10 ==a || n%10 ==b)
            n=n/10;
        else return false;
    }
    return true;
}
long long getC(long long int n,long long int i) {
        long long res = fact[n];
        long long div = fact[n-i] * fact[i];
        div %= mod;  //div = binpow(div, mod - 2, mod);
        div=modpow(div,mod-2);
        return (res * div) % mod;
}
int main() 
{
    fastio
    fillFact();
    ll a,b,n,i,j,x,y;
    cin >> a >> b >> n;
    long long ans = 0;
    for(int i = 0; i <= n; i++) {
            long long expsum = a * i + b*(n-i);
            if (check(expsum, a, b)) {
                    ans += getC(n, i);
                    ans %= mod;
            }
    }
    cout << ans << "\n";
    return 0;
}
