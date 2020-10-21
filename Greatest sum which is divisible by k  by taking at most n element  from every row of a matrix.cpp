#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

int n,m,k,lim,ara[72*72];
bool seg[72*72];
ll dp[72*72][36][72];
ll fun(int indx , int take , int sum)
{
    if(take>lim) return INT_MIN;
    if(indx>n*m)
    {
        if(sum%k) return INT_MIN;
        return 0;
    }
    if(seg[indx]) take=0;
    if(dp[indx][take][sum]!=-1) return dp[indx][take][sum];
    ll ret = fun(indx+1,take,sum);
    ret = max(ret , ara[indx]+fun(indx+1,take+1,(sum+ara[indx])%k));
    return dp[indx][take][sum]=ret;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    lim = m/2;
    for(int i = 1 ; i <= n*m ; i++ ) cin >> ara[i];
    for(int i = 1 ; i <= n*m ; i+=m ) seg[i]=1;
    memset(dp,-1,sizeof dp);
    printf("%lld\n",fun(1,0,0));
    return 0 ;
}
