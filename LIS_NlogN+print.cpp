#include<bits/stdc++.h>
using namespace std;
#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
#define  pii            pair < ll, ll>
#define  ff             first
#define  ss             second
ll ara[200005];

ll LIS(ll n)
{
    ll temp[n+2],res[n+2],val[n+2],i,sz=1;
    memset(res,-1,sizeof res);
    temp[0]=0;
    val[0]=ara[0];
    for( i = 1 ; i< n ; i++)
    {
        ll indx = lower_bound(val,val+sz,ara[i])-val;
        temp[indx]=i;
        val[indx]=ara[i];
        if(indx!=0) res[i]=temp[indx-1];
        if(indx==sz) sz++;
    }
    //Printng_LIS
    vector<ll>path;
    ll indx = temp[sz-1] ;
    path.push_back(ara[indx]);
    while(res[indx]!=-1)
    {
        path.push_back(ara[res[indx]]);
        indx = res[indx];
    }
    for( i = sz-1 ; i >= 0 ; i--) cout<<path[i]<<" ";
    cout<<endl;
    return sz ;
}


int main()
{
    CIN;
    ll a , b , i , j ;
    cin >> a ;
    for( i = 0 ; i < a ; i++) cin >> ara[i];
    cout<<LIS(a)<<endl;
    return 0 ;
}
