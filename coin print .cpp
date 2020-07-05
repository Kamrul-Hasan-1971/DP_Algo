//Complexity (taka*coin number)

#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             int
#define  pb             push_back
#define  all(a)         a.begin(),a.end()
#define  rall(a)        a.rbegin(),a.rend()
vector<ll>v1,ans;
ll a ;
void fun1(ll x)
{
    if(x>a) return;
    v1.pb(x);
    x*=10ll;
    fun1(x);
    x+=1ll;
    fun1(x);
}
const ll INF = 10000000;
ll fun(ll n)
{
    ll M[n+3];
    M[0] = 0;
    ll S[n+3];
    S[0] = 0;
    ll i, j;
    for(j=1; j<=n; j++)
    {
        ll minimum = INF;
        ll mn=0;

        for(i=1; i<v1.size(); i++)
        {
            if(j >= v1[i])
            {
                if((1+M[j-v1[i]]) < minimum)
                {
                    minimum = 1+M[j-v1[i]];
                    mn = i;
                }
            }
        }
        M[j] = minimum;
        S[j] = mn;
    }

    ll l = n;
    while(l>0)
    {
        ans.pb(v1[S[l]]);
        l = l-v1[S[l]];
    }
    return M[n];
}

int main()
{
    CIN;
    cin>> a;
    fun1(1);
    v1.pb(0);
    sort(all(v1));
    ll sz=v1.size();
    cout<<fun( a)<<endl;
    for(ll i = 0 ; i< ans.size() ; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0 ;
}
