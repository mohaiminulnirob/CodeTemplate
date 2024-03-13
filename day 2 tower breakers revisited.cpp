#include<bits/stdc++.h>
using namespace std;
int grundy[1000001];
vector<int>divisors[1000001];

void sieve()
{
    for(int i=1;i<1000001;i++)
    {
        for(int j=i;j<1000001;j=j+i)
        {
            if(i!=j)
            divisors[j].push_back(i);
        }
    }
}

int calculateMex(set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

int calculateGrundy(int X)
{
     if(X==1)
    {
        return 0;
    }
    if(grundy[X]!=-1)
    {
        return grundy[X];
    }
    set<int>s;
    for(int i=0;i<divisors[X].size();i++)
    {
        int Y=divisors[X][i];

            s.insert(calculateGrundy(Y));
    }
    grundy[X] = calculateMex (s);
    return grundy[X];
}


int main()
{
    sieve();
    memset(grundy,-1,sizeof(grundy));
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int xor_sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            xor_sum=xor_sum^calculateGrundy(x);
        }
        if(xor_sum==0)
            cout<<"2"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}

