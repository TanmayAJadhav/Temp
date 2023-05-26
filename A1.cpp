#include<iostream>
#include<vector>
#include<unordered_map>    
#include<queue>
using namespace std;

vector<bool>visited;
unordered_map<int,vector<int>>graph;
void dfs(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    for(auto child:graph[v])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}

vector<int>path;
bool flag = false;
void dfssearch(int v, int node)
{
    visited[v] = true;
    // cout<<v<<" ";
    path.push_back(v);

    if(v==node || flag == true)
    {
        flag = true;
        return;
    }

    for(auto child:graph[v])
    {
        if(!(visited[child]))
        {
            dfssearch(child,node);
        }
    }
}


queue<int>q;
void bfs()
{
    if(q.empty())
    {
        return;
    }
    int node = q.front();
    q.pop();
    cout<<node<<" ";
    for(auto child:graph[node])
    {
        if(!visited[child])
        {
            visited[child] = true;
            q.push(child);
        }
    } 
    bfs();
}

int main()
{
    int E,V;

    cout<<"Enter number of vertices : \n";
    cin>>V;
    cout<<"Enter number of Edges : \n";
    cin>>E;

    
    visited.resize(V+1);
    for(int i = 0; i < E; i++)
    {
        int v1,v2;
        cout<<"Enter vertice 1 : \n";
        cin>>v1;
        cout<<"Enter vertice 2 : \n";
        cin>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

        cout<<"Edge added successfully \n";
    }

    for(int i = 1; i < graph.size(); ++i)
    {
        cout<<i<<" : ";
        for(int j = 0; j < graph[i].size(); ++j)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    int start;
    cout<<"Enter starting vertex : \n";
    cin>>start;

    cout<<"Dfs traversal \n";
    dfs(start);
    
    cout<<endl;
    
    for(int i = 0; i < V+1; ++i)
    {
        visited[i] = false;
    }
    
    q.push(start);
    visited[start] = true;

    cout<<"Bfs traversal \n";
    bfs();
    cout<<endl;

    return 0;

}

