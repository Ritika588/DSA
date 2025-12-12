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

bool checkCycle(int child, int parent, map <int, bool> &visited, map <int, int> &pt, map <int, set<int>>adjList)
{
    visited[child] = true;
    pt[child] = parent;

    for(auto &nbr : adjList[child])
    {
        if(! visited[nbr]){
            if(checkCycle(nbr, child, visited, pt, adjList))
            {
                return true;
            }
        }

        if(pt[child] != nbr)
        {
            return true;
        }
    }
    return false;
}


bool checkCycleDFS( map <int, set<int>> adjList)
{
    map <int, bool> visited;
    map <int, int> pt;

    for(auto &i : adjList)
        visited[i.first] = false;
    
    for(auto &i : adjList)
    {
        int node = i.first;
        pt[node] = -1;

        if(!visited[node])
        {
            visited[node] = true;
            for(auto &nbr : adjList[node])
            {
                if(!visited[nbr])
                {
                    if (checkCycle(nbr, node, visited, pt, adjList))
                        return true;
                }
            }
        }
    }
    return false;
}
/*  USING BFS

// Track parent
// Condition for cycle -> visited = true but not parent



bool checkCycleBFS(map <int, set<int>> &adjList)
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
*/

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

    if (!checkCycleDFS(g.adjList))
    {
        cout << "No cycle present." << endl;
    }
    else{
        cout << "Cycle detected." << endl;
    }

    return 0;
}
