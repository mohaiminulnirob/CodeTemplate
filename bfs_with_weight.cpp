#include<bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>>adjlist;
long long vis[30005][2];
int tnode,current;

int bfs(int start,long long mdis)
{
    queue<int>q;
    q.push(start);
    vis[start][0]=1;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        for(auto child:adjlist[current])
        {
            if(vis[child.first][0]!=1)
            {
            q.push(child.first);
            vis[child.first][0]=1;
            vis[child.first][1]=vis[current][1]+child.second;
            if(vis[child.first][1]>=mdis)
            {
                mdis=vis[child.first][1];
                tnode=child.first;
            }

            }
        }
    }
    return tnode;
}
int main()
{
    int t,c=0;
    cin>>t;
    while(t--)
    {
        c++;
        memset(vis,0,sizeof(vis));
        adjlist.clear();
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adjlist[u].push_back(std:: make_pair(v,w));
            adjlist[v].push_back(std:: make_pair(u,w));
        }
        int node1=bfs(0,0);
        memset(vis,0,sizeof(vis));
        int node2=bfs(node1,0);
        long long ans=vis[node2][1];
       cout<<"Case "<<c<<": "<<ans<<endl;
    }
    return 0;
}
