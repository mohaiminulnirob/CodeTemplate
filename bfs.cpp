#include<bits/stdc++.h>
using namespace std;
vector<int>a[10000];
int vis[10000];
int level[1000];
int orig[1000];
int current;
void bfs(int start)
{
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        cout<<current<<" ";
        for(auto child:a[current])
        {
            if(vis[child]!=1)
            {
            q.push(child);
            vis[child]=1;
            level[child]=level[current]+1;
            orig[child]=current;
            }
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(1);
    int i=current;
    cout<<current<<endl;
    while(i!=1)
    {
        cout<<orig[i]<<" ";
        i=orig[i];
    }
}
