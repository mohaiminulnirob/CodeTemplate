#include<bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	int t;
	cin>>t;
	int cs=0;
	while(t--)
	{
		cs++;
        int n;
        cin>>n;
        int a[n];
        int xs=0,c=0;
        for(int i=0;i<n;i++){
           cin>>a[i];
           xs^=a[i];
        }
        for(int i=0;i<n;i++){
        	int xs1=xs^a[i];
        	if(xs1<a[i] && xs1>=0)
        		c++;
        }
        cout<<"Case "<<cs<<": "<<c<<'\n';
	}
	return 0;
}