#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
int graph[505][505];
int dis[505];
int vis[505];
int n,m;
void dijkstra(int x){
	dis[x]=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({dis[x],x});
	while(!pq.empty()){
		int u=pq.top().second;
		vis[u]=1;
		pq.pop();
		for(int i=1;i<=n;i++){
			if(graph[u][i] && !vis[i] && dis[i]>dis[u]+graph[u][i]){
				dis[i]=dis[u]+graph[u][i];
				//vis[i]=1;
			    pq.push({dis[i],i});
			}

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

	int t;
	cin>>t;
	int cs=0;
	while(t--)
	{
		cs++;
		memset(vis,0,sizeof(vis));
		memset(graph,0,sizeof(graph));
		//int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
        {
           dis[i]=INT_MAX;
        }
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			x++;
			y++;
			if(graph[x][y]!=0)
            {
                if(z<graph[x][y])
                {
                    graph[x][y]=z;
                    graph[y][x]=z;
                }

            }
            else {
                graph[x][y]=z;
                graph[y][x]=z;
            }
		}
		int src;
		cin>>src;
		src++;
		dijkstra(src);
		cout<<"Case "<<cs<<": "<<endl;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]!=INT_MAX)
                 cout<<dis[i]<<endl;
            else cout<<"Impossible"<<endl;
        }
        
	}
	return 0;
}
