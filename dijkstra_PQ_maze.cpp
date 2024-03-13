#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int dis[1000][1000];
bool vis[1000][1000];
int n,m;
int graph[1000][1000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>> pq;

void dijkstra(int x,int y)
{
    dis[x][y]=graph[x][y];
    pq.push(make_pair(dis[x][y],make_pair(x,y)));
    while(!pq.empty())
    {
        pair<int,int>u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        //if(d==dis[u.first][u.second])
        if(vis[u.first][u.second])
            continue;
        vis[u.first][u.second]=1;
        for(int l=0;l<=3;l++)
        {
            int i=u.first+dx[l];
            int j=u.second+dy[l];
            if (i>=0 && i<n && j>=0 && j<m
            && dis[u.first][u.second] != INT_MAX
            && dis[u.first][u.second] + graph[i][j] < dis[i][j])
            {
                dis[i][j] = dis[u.first][u.second] + graph[i][j];
               pq.push(make_pair(dis[i][j],make_pair(i,j)));
            }
        }

    }

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[i][j] = INT_MAX;
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>graph[i][j];
            }
        }
        dijkstra(0,0);
        cout<<dis[n-1][m-1]<<endl;
    }
    return 0;
}
