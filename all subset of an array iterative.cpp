#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

vector<vector<ll>>v1;
vector<ll>v2;

int main()
{
    ll  i , j , n = 4 , x;
    ll ara[]={1,2,3,4};

    for( i = 0 ; i < n ; i++)
    {
        ll x = v1.size();
        for( j = 0 ; j < x ; j++)
        {
            v1.push_back(v1[j]);
            v1.back().push_back(ara[i]);
        }
        v2.clear();
        v2.push_back(ara[i]);
        v1.push_back(v2);
    }

    for( i= 0 ; i < v1.size() ; i++)
    {
        for( j= 0 ; j < v1[i].size(); j++)
        {
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
}

