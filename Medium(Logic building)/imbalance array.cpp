#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     ll          long long int 
#define     pb         push_back
#define     ppb         pop_back
#define mod 1000000007

ll cal_Min(ll n,ll a[])
{
    stack<ll> st;
    ll left[n],right[n],i;
    st.push(0),left[0]=0,right[n-1]=n-1;
    for(i=1;i<n;i++)
    {
        if(st.empty())
        {
            left[i]=0;
            st.push(i);
        }
        if(!(st.empty()) && a[i]>a[st.top()])
        {
            left[i]=i;
            st.push(i);
        }
        else if(a[i]<=a[st.top()])
        {
            while(!(st.empty()) && a[i]<=a[st.top()])
            {
                st.pop();
            }
            if(st.empty())
                left[i]=0;
            else 
                left[i]= st.top() +1;
            st.push(i);
        }
    }
    while(!st.empty())
    {
        st.pop();
    }
    st.push(n-1);
    for(i=n-2;i>=0;i--)
    {
        if(st.empty())
        {
            right[i]=n-1;
            st.push(i);
        }
        else if(a[i]>=a[st.top()])
        {
            right[i]=i;
            st.push(i);
        }
        else if(a[i]<a[st.top()])
        {
            while(!(st.empty()) && a[i]<a[st.top()])
            {
                st.pop();
            }
            if(st.empty())
                right[i]=n-1;
            else 
                right[i]= st.top() -1;
            st.push(i);
        }
    }
    /*for(i=0;i<n;i++)
    {
        cout << left[i] << " ";
    }
    cout << "\n";
    for(i=0;i<n;i++)
    {
        cout << right[i] << " ";
    }
    cout << "\n";*/
    ll minsum=0;
    for(i=0;i<n;i++)
    {
        minsum+=((right[i]-i+1)*(i-left[i]+1)*(a[i]));
        //cout << minsum << "  " ;
    }
    return minsum;
}
int main() 
{
    fastio
    ll n,i,j,x,y;
    cin >> n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll minsum=cal_Min(n,a);     //cout << minsum << " \n";
    for(i=0;i<n;i++)
    {
        a[i]=-1*a[i];
    }
    ll maxsum=cal_Min(n,a);        //cout << maxsum << "\n";
    ll ans= minsum+maxsum;
    ans=ans*(-1);
    cout << ans ;
    return 0;
}
