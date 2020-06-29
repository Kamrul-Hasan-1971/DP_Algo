#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int

vector<ll>v1,v2,v3;
string s1, s2, s3;
ll arr[100];
ll cnt,a,b,ans;
void fun2(ll n)
{
    ll y = 0;
    for(ll i = 0 ; i < a ; i++)
    {
        ll x;
        x=s1[i]-'0';
        if (x == 1) y = (y * 2 + 1) % n;
        else if (x == 0) y = (y * 2) % n;
    }
    if (y % n == 0) ans++;
}
void chk( ll n)
{
    for (ll i = 0; i < n; i++)
    {
        s1[v1[i]]=arr[i]+'0' ;
    }
    fun2(b);
}

void fun1(ll n, ll i)
{
    if (i == n)
    {
        chk(n);
        return;
    }
    arr[i] = 0;
    fun1(n, i + 1);
    arr[i] = 1;
    fun1(n, i + 1);
}
int main()
{
    CIN;
    ll  c,d,e,f,i,j,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    cin>> T ;
    while(T--)
    {
        ans=0;
        v1.clear();
        memset(arr,0,sizeof arr);
        cnt=0;
        cin>>a>>b>>s1;
        for( i = 0 ; i < s1.size() ; i++)
        {
            if(s1[i]=='_')
            {
                v1.push_back(i);
                cnt++;
            }
        }
        fun1(cnt,0);
        cout<<ans<<endl;
    }
    return 0 ;
}
///prllf & cout ekshatey use korbo nah
