#include <bits/stdc++.h>
using namespace std;

int visited[200];
vector<int>graph[200];

void dfs(int source)
{
    visited[source]=1;
    for(int i=0; i<graph[source].size(); i++)
    {
        int next=graph[source][i];

        if(visited[next]==0) dfs(next);
    }
}

int main()
{
//    input
//    10 8
//    0 1
//    1 2
//    1 3
//    3 4
//    5 6
//    7 8
//    9 9
//    3 0


   int vertice, edge;
   cin>>vertice>>edge;

   for(int i=0; i<edge; i++)
   {
       int a,b;
       cin>>a>>b;
       graph[a].push_back(b);
       graph[b].push_back(a); //For undirected graph

   }
   cout<<endl;
   for(int i=0; i<vertice; i++)
   {
       cout<<i<<"-> ";
    for(int j=0; j<graph[i].size(); j++)
    cout<<graph[i][j]<<' ';
   cout<<endl;

   }

   dfs(0); // source 0

   cout<<endl;
   for(int i=0; i<vertice; i++)
   {
       if(visited[i]==0) cout<<i<<" node is not visited"<<endl;
       else cout<<i<<" node is visited"<<endl;
   }

   //Checking connected components
   int cnt=1;
   for(int i=0; i<vertice; i++)
   {
       if(visited[i]==0  & graph[i].size()!=0)
       {
           cnt++;
           dfs(i);
       }
   }
   cout<<"Total connected components: "<<cnt<<endl;


   return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;

int visited[100];
vector<int>graph[100];
vector<int>path[100];

void dfs(int source, int times)
{
    if(visited[source]==0 && graph[source].size()!=0) path[times].push_back(source);

    visited[source]=1;

    for(int i=0; i<graph[source].size(); i++)
    {
        int next=graph[source][i];

        if(visited[next]==0) dfs(next,times);
    }
}

int main()
{

    10 7
    0 3
    0 1
    1 5
    1 3
    4 6
    6 7
    8 9


    int vertice, edge;
    cin>>vertice>>edge;

    for(int i=0; i<edge; i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    cout<<endl<<"Adjacent list:"<<endl;
    for(int i=0; i<vertice; i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }

    int cnt=0;
    for(int i=0; i<vertice; i++)
    {
        if(visited[i]==0 && graph[i].size()!=0)
        {

            dfs(i,i);
            cnt++;

        }
    }
    cout<<"\nConnected Paths: "<<endl;
    int charac=97;
    for(int i=0; i<vertice; i++)
    {
        if(path[i].size()!=0) cout<<(char)charac<<"-> ";
        for(int j=0; j<path[i].size(); j++)
        {
            cout<<path[i][j]<<' ';
        }
        if(path[i].size()!=0)
        {
            charac++;
            cout<<endl;
        }
    }
    cout<<"\nConnected components: "<<cnt<<endl;




    return 0;
}

*/
