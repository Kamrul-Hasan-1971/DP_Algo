#include<bits/stdc++.h>
using namespace std;

#define           ll               long long int

vector<ll> v1, v2 ;

ll Fun()
{
    v2.push_back( v1[ 0 ] ) ;

    for(ll i = 1; i < v1.size(); i++)
    {
        if( v2.back() <= v1[ i ] ) //  "<" for strictly increasing sequence
        {
            v2.push_back( v1[ i ] ) ;
        }
        else
        {
            ll pos =  upper_bound( v2.begin(),v2.end(), v1[ i ] )-v2.begin() ;//lower_bound for strictly increasing sequence
            v2[ pos ] = v1[ i ] ;
        }
    }
    return ( ll ) v2.size() ;
}

int main()
{
    ll n, a , i;
    cin >> n ;
    for(  i = 0 ; i < n ; i ++ )
    {
        cin >> a ;
        v1.push_back( a ) ;
    }

    cout << Fun() << endl ;
    return 0 ;
}
