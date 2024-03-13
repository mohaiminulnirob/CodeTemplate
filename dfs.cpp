#include<bits/stdc++.h>
using namespace std;
vector<int>a[10000];
int vis[10000];
void dfs(int start)
{
    cout<<start<<endl;
    vis[start]=1;
    for(auto child: a[start])
    {
        if(vis[child]!=1)
        {
            dfs(child);
        }
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
    dfs(1);

}
