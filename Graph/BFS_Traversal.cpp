#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph
{
    public:
    map <int, set<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].insert(v);
        if(direction == 0)
        {
            adjList[v]. insert(u);
        }
    }

    void print()
    {
        for(auto &i :adjList)
        {
            cout << i.first << "->";
            for(auto &j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};


void BFS(map <int, set<int>> adjList, int nodes)
{
    queue<int> q;
    map <int, bool> visited;

    // Mark all nodes as unvisited
    for( auto &i : adjList)
        visited[i.first] = false;


    for(auto &i : adjList)
    {
        int start = i.first;

        if(!visited[start] )
        {
            q.push(i.first);
            visited[start] = true;
        
            while(! q.empty())
            {
                int temp = q.front();
                q.pop();
                cout << temp << " ";

                for(auto &j : adjList[temp])
                {
                    if (! visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }  
            }
        }
    }
}


int main()
{
    int n;
    cout << "Enter the no of Nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the no of edges: " << endl;
    cin >> m;

    int u, v;
    cout << "Enter the graph: " << endl;

    graph g;
    for(int i = 0; i< m; i++)
    {
        cin >> u;
        cin >> v;
        g.addEdge(u,v,0);   
    }

    g.print();

    cout << "BFS Traversal of the Graph is: " << endl;
    BFS(g.adjList, n);

    return 0;

}