#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
    public:

    map <int , set<int>> adjList;
    
    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
    }

    void printAdjList()
    {
        for( auto &i : adjList)
        {
            cout << i.first << "->" ;
            for(auto &j : i.second)
            {
                cout << j << "," ;
            }
            cout << endl;
        }
        cout << endl;
    }


};

bool checkCycle(int node, map <int, bool> &visited, map <int, bool> &dfsvisited, map <int , set<int>> adjList)
{
    visited[node] = true;
    dfsvisited[node] = true;
    
    for(auto & nbr : adjList[node])
    {
        
        if(! visited[nbr])
        {
            if (checkCycle(nbr, visited, dfsvisited, adjList))
                return true;
        } 

        if (dfsvisited[nbr])
        {
            return true;  // dfvis = true and vis = true - cycle present
        }  
    }
    
    dfsvisited[node] = false;
    return false;

}

bool cycleDetect(map <int , set<int>> adjList)
{   
    map <int, bool> dfsvisited;
    map <int, bool> visited;

    for (auto &i: adjList)
        visited[i.first] = false;

    for (auto &i : adjList){
        int node = i.first;

        if( ! visited[node])
        {
            if (checkCycle(node, visited, dfsvisited, adjList))
                return true;
        }
    }
    return false;

}

int main()
{
    int nodes, edges;
    cout << "Enter the no of nodes: " << endl;
    cin >> nodes;

    cout << "Enter the no. of edges: " << endl;
    cin >> edges;

    cout << "Enter the graph (u,v) " << endl;
    graph g;

    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v);
    }

    cout << "Adjacency List for the Graph is: " << endl;
    g.printAdjList();

    if (cycleDetect(g.adjList))
        cout << "Cycle is present." << endl;
    else
        cout << "Cycle not present" << endl;

    return 0;

}
