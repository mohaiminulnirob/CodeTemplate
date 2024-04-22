#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
int a[35];
int grundy[N];
int n,m;

int calculateMex(bool visited[]){
	int mex=0;
	while(visited[mex])
		mex++;
	return mex;
}

int calculateGrundy(int x){
	if(x==0 || x<a[0])
		return 0;
    if(grundy[x]!=-1)
    	return grundy[x];
    bool visited[35];
	memset(visited,false,sizeof visited);
	for(int i=0;i<m;i++){
		if(x>=a[i])
			visited[calculateGrundy(x-a[i])]=true;
	}
	grundy[x]=calculateMex(visited);

	return grundy[x];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	int t;
	cin>>t;
	while(t--)
	{
		memset(grundy,-1,sizeof(grundy));
        cin>>n>>m;
        for(int i=0;i<m;i++){
        	cin>>a[i];
        }
        sort(a,a+m);
        int xs=0;
        for(int i=0;i<n;i++){
        	int x;
        	cin>>x;
        	xs^=calculateGrundy(x);
        }
        if(!xs)
        	cout<<"Vinit"<<'\n';
        else cout<<"Ada"<<'\n';
	}
	return 0;
}