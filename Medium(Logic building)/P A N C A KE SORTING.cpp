#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() 
{
    //fastio
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,i;
        cin >> n >> k;
        char a[n];
        string s(""), s1, f,l;
        //s.clear();
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            s.push_back(a[i]);
        }
        map<string,int> m;
        m[s]=0;
        s1=s;
        //cout << s1 << "\n";
        sort(s1.begin(),s1.end());//,greater<char>());
        reverse(s1.begin(),s1.end());
        //cout << s1 << "\n";
        queue<string> q;
        q.push(s);
        while(!(q.empty()))
        {
            f=q.front();
            q.pop();
            if(f==s1)       break;
            for(i=0;i<n;i++)
            {
                if(i+k-1 >= n)
                    break;
                l=f;
                reverse(l.begin()+i, l.begin()+i+k);
                if(m.count(l)==0)
                {
                    m[l]=m[f]+1;
                    q.push(l);
                }
            }
        } 
        if(m.count(s1) > 0)     cout << m[s1] << "\n";
        else    printf("NP\n");
        m.clear();
    }
    return 0;
}
