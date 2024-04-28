#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,node;
int graph[5005][3];
int dis[2505];
int parent[2505];
bool impossible;
void bellmanford(int src){
	dis[src]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]){
				dis[graph[j][1]]=dis[graph[j][0]]+graph[j][2];
				parent[graph[j][1]]=graph[j][0];
			}
		}
	}
	for(int j=0;j<m;j++){
		if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]){
            node=graph[j][1];
            parent[graph[j][1]]=graph[j][0];
			impossible=true;
			break;
		}
	}

}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	int t=1;
	//cin>>t;
	while(t--)
	{
		impossible=false;
        cin>>n>>m;
        for(int i=0;i<m;i++){
        	int x,y,z;
        	cin>>x>>y>>z;
        	if(x==y && z<0){
        		impossible=true;
        		node=x;
        		parent[node]=x;

        	}
        	graph[i][0]=x;
        	graph[i][1]=y;
        	graph[i][2]=z;
        }
        for(int i=0;i<n;i++)
	    {
		dis[i]=INT_MAX;
	    }
        for(int i=1;i<=n;i++){
        	if(impossible)
        		break;
        	if(dis[i]==INT_MAX)
        		bellmanford(i);

        }
        if(impossible){
        	cout<<"YES"<<'\n';
        	vector<int>cycle;
        	for(int v=node;;v=parent[v]){
        		cycle.push_back(v);
        		if(v==node && cycle.size()>1)
        			break;
        	}
            reverse(cycle.begin(),cycle.end());
            for(auto u:cycle){
            	cout<<u<<" ";
            }
            cout<<"\n";
        }
        else cout<<"NO"<<'\n';
        
	}
	return 0;
}