#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define pb push_back
int main() 
{
    fastio
    ll n,ncopy;
    cin >> n;   ncopy=n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    priority_queue<ll> pq;
    ll cnt=1;
    for(ll i=1;i<n;i++)
    {
        if(a[i] == a[i-1])
        {
            cnt++;
        }
        else {
            pq.push(cnt);
            cnt=1;
        }
    }
    pq.push(cnt);
    /*while(!pq.empty())
    {cout << pq.top() << " ";   pq.pop();}*/
    ll k=n/3;  //n=n-(k*3);
    while(!(pq.empty()) && k>0)
    {
        if(pq.top() > k)
        {
            ll x= pq.top();
            pq.pop();
            n=n-(x-k);
            x=k;
            pq.push(x);
            k=n/3;
        }
        else {
            pq.pop();
        }
    }
    cout << k << "\n";
    n=ncopy;
    if(k>0)
    {
        ll i=0,c=0; vector<ll> v1,v2,v3;
        for(;c<k;i++,c++) {
            v1.pb(a[i]);
        }
        c=0;
        while(a[i]==v1[0]) {    i++;   }
        c=0;
        while(c<k) {
            if(a[i] > v1[c]){v2.pb(a[i]);    c+=1;}   
            i+=1;
        }
        while(a[i]==v2[0]) {   i++;    }
        c=0;
        while(c<k && i<n) {
            if(a[i] > v2[c]) {v3.pb(a[i]);    c+=1;}   
            i+=1;
        }
        while(i<n){
            v3.pb(a[i]); i++;
        }
        for(i=0;i<k;i++) {
            cout << v3[i] << " " << v2[i] << " " << v1[i] << "\n";
        }
    }
    
    return 0;
}
