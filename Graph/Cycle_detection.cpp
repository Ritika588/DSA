#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    map <int, set<int>>adjList;

    void addEdge( int u, int v, int direction)
    {
        adjList[u].insert(v);
        if(direction == 0)
        {
            adjList[v].insert(u);
        }
    }

    void printAdjList ()
    {
        for(auto &i : adjList)
        {
            cout << i.first << "->" ;
            for(auto &j : i.second)
            {
                cout << j << "," ;
            }
            cout << endl;
        }
    }
};


// Track parent


// Condition for cycle -> visited = true but not parent
bool checkCycle(map <int, set<int>> &adjList)
{
    queue <int> q;
    map <int, int> parent;
    map <int, bool> visited;

    for(auto &i : adjList)
    {
        int node = i.first;
        if(! visited[node])
        {
            q.push(node);
            visited[node] = true;
            parent[node] = -1;

            while(! q.empty())
            {
                int temp = q.front();
                q.pop();

                for(auto &nbr : adjList[temp])
                {
                    if(visited[nbr] && nbr != parent[temp])
                    {
                        cout << nbr << " is not the parent of " << temp << endl;
                        return true;
                    } 
                    else if( !visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = temp;
                    }
                }
            }
        }

    }
    return false;
}

int main()
{
    int nodes, edges;
    cout << "Enter the no. of nodes: " << endl;
    cin >> nodes;

    cout << "Enter the no. of edges: " << endl;
    cin >> edges;

    int direction;
    cout << "Enter the direction of the graph: " << endl; // 0 - undirected, 1 - directed
    cin >> direction;

    cout << "Enter the graph (u,v) " << endl;
    Graph g;

    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v, direction);
    }

    cout << "Adjacency List for the Graph is: " << endl;
    g.printAdjList();

    if (!checkCycle(g.adjList))
    {
        cout << "No cycle present." << endl;
    }
    else{
        cout << "Cycle detected." << endl;
    }

    return 0;
}
