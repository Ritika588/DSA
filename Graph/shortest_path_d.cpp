/* The idea is to find the topo sort so that every node gets the min distance from the starting node.
    Take a distance vector and initialize all nodes to infinity.
    From the source node, keep minimizing the distance of each node.*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public: 
    map <int, list <pair<int, int>>>adjList;



    void addEdge (int u, int v , int weight)
    {
        pair <int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    void printAdjList()
    {
        for(auto &i : adjList)
        {
            cout << i.first << "->" ;
            for(auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "]";
            }
            cout << endl;
        }
    }


    
    // DFS
    void DFS(int node, stack <int> &s, map <int, bool> &visited)
    {
        visited[node] = true;
        for(auto &j : adjList[node])
        {
            if(! visited[j.first])
                DFS(j.first, s, visited);
        }
        s.push(node);
    }



    void shortest_path(int top, vector<int> &dist)
    {
        for(auto &nbr : adjList[top])
        {
            dist[nbr.first] = min(dist[nbr.first], dist[top] + nbr.second);
        }   
    }


    
};

int main()
{
    int nodes, edges, weight;

    cout << "Enter the no of node: " << endl;
    cin >> nodes;
    cout << "Enter the no of edges: " << endl;
    cin >> edges;

    cout << "Enter the graph and weight: " << endl;
    Graph g;

    for(int i =0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v >> weight;
        g.addEdge(u,v, weight);
    }

    g.printAdjList();

    //topo_sort
    stack <int> topo;
    map <int, bool> visited;


    for(auto i : g.adjList)
    {
        visited[i.first] = false;
    }

    for(auto i : g.adjList)
    {
        int node = i.first;
        if( !visited[node])
        {
            g.DFS(node, topo, visited);
        }
    }



    int src, end;
    cout << "Enter source node: " << endl;
    cin >> src;

    vector <int> distance(nodes, INT_MAX);
    distance[src] = 0;

    while(! topo.empty())
    {
        int top = topo.top();
        topo.pop();

        if(distance[top] != INT_MAX)
        {
            g.shortest_path(top, distance);
        }
    }

    for(auto &i : distance)
        cout << i << endl;

    return 0;
}