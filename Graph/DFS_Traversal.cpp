#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map <int, set <int>>adjList;

    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    void printAdjList()
    {
        for(auto &i : adjList)
        {
            cout << i.first << "->" ;
            for(auto &j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};



void DFS(int node, map <int, set<int>> adjList, map <int, bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for(auto &i : adjList[node])
    {
        if(!visited[i]) 
            DFS(i, adjList, visited);
    }
}



int main()
{
    int nodes, edges;
    cout << "Enter the no. of nodes: " << endl;
    cin >> nodes;

    cout << "Enter the no. of edges: " << endl;
    cin >> edges;

    Graph g;  

    // make a graph
    for(int i = 0; i <edges; i++)
    {
        int u, v;
        cout << "Enter the nodes (u,v)" << endl;
        cin >> u >> v;
        g.addEdge(u,v);
    }

    cout <<"Printing the Adjacency List of the Graph :-> " << endl;
    g.printAdjList();


    map <int, bool> visited;

    // mark all nodes a s unvisited in the map
    for(auto &i : g.adjList){
        visited[i.first] = false;
    }

    cout << "Printing the DFS Traversal of the graph :" << endl;
    // Traverse for all nodes (components)
    for(auto &i : g.adjList)
    {
        int node = i.first;

        if(! visited[node]){
            DFS(node, g.adjList, visited);
            cout << endl ;         // separates components
        }

    }
    return 0;
}
