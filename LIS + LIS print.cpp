#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           pb               push_back
#define           zero(a)              memset(a,-1,sizeof a)
#define           siz              1000

ll n ,dp[siz],dir[siz];
vector<ll>value;

void solutionPrint(ll start)
{
    while(dir[start]!=-1)
    {
        cout<<value[start]<<" ";
        start=dir[start];
    }
    cout<<value[start]<<endl;
}

ll longest( ll u )
{
    if(dp[u]!=-1) return dp[u];
    ll maxi = 0;
    for( ll v = u+1 ; v<n ; v++)
    {
        if(value[v]>value[u])
        {
            if(longest(v)>maxi)
            {
                maxi=longest(v);
                dir[u]=v;
            }
        }
    }
    dp[u]=1+maxi;
    return dp[u];
}



int main()
{
    ll  b , i ;
    zero(dp);
    zero(dir);

    cin >> n ;
    for( i = 0 ;i < n ; i++)
    {
        cin >> b;
        value.pb(b);
    }

    ll LIS = 0 , start ;
    for(ll i = 0 ; i < n ; i++ )
    {
        printf("longest path from %lld : %lld\n",i+1,longest(i));
        if(longest(i)>LIS)
        {
            LIS=longest(i);
            start=i;
        }
    }
    printf("LIS = %lld Starting point %lld\n",LIS,start+1);
    solutionPrint(start);
    return 0 ;
}
