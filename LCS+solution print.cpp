#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           pb                 push_back
#define           zero(a)            memset(a,-1,sizeof a)

ll N1, N2, dp[103][103];
string ans;
string v1 , v2 ;

void printAll(int i,int j)
{
	if( i >= N1 || j >= N2 ){
		cout<<ans<<endl;
		return;
	}
	if(v1[i]==v2[j]){
		ans+=v1[i];
		printAll(i+1,j+1);
		ans.pop_back();
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else
		{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}

ll LCS(ll i, ll j )
{
    if( i >= N1 || j >= N2 )
        return 0 ;

    ll ret1 = 0 ;
    if( dp[i][j]!=-1 )
        return dp[i][j];
    if( v1[i] == v2[j] )
    {
        ret1 = 1 + LCS( i+1, j+1 ) ;
    }
    else
    {
        ll x = LCS( i+1, j ) ;
        ll y = LCS( i, j+1 ) ;
        ret1 = max( x, y ) ;
    }
    return dp[i][j] = ret1 ;
}


