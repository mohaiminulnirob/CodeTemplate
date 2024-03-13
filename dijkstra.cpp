#include<bits/stdc++.h>
using namespace std;
int graph[105][105];
int dist[105];
bool sptSet[105];
int V,E,src=1;

int minDistance()
{
	int min = INT_MAX, min_index;

	for (int v = 1; v <=V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void dijkstra()
{
	for (int i = 1; i <= V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;
	for (int count = 1; count < V ; count++) {
		int u = minDistance();
		sptSet[u] = true;

		for (int v = 1; v <= V; v++)

			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

}

int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        cs++;
        cin>>V>>E;
        memset(graph,0,sizeof(graph));
        for(int i=0;i<E;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
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
        dijkstra();
        for(int i=1;i<=V;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
    }
    return 0;
}

