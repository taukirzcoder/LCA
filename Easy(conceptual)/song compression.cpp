#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
struct song{
    ll cur,req,diff;
};
bool cmp(song i1, song i2)
{
    return i1.diff > i2.diff;
}
int main() 
{
    fastio
    ll n,maxval=0,i,j,sum=0;
    cin >> n >> maxval;
    song songs[n];
    for(i=0;i<n;i++)
    {
        cin >> songs[i].cur >> songs[i].req;
        songs[i].diff = songs[i].cur - songs[i].req;
    }
    ll sumcur=0,sumreq=0;
    sort(songs,songs+n,cmp);
    for(i=0;i<n;i++)
    {
        //cout << songs[i].diff << "\n";
        sumcur+=songs[i].cur;
    }
    ll x= sumcur - maxval;
    ll cnt=0;
    for(i=0;i<n;i++)
    {
        if(sumreq >= x)
            break;
        sumreq+= songs[i].diff;
        cnt++;
    }
    if(i == n && sumreq < x)  cout << "-1";
    else 
        cout << cnt ;
    return 0;
}
