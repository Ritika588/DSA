/* The idea is to find the indegree of all the nodes.
    take the node whose indegree is 0, print it, remove it 
    and dec all the connected nodes by 1.
    then repeat again for the nodes with 0*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:

    map< int, set<int>> adjList;
    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
    }


    void print()
    {
        for(auto &i : adjList)
        {
            cout << i.first << "->" ;
            for(auto &j : i.second)
            {
                cout << j<< ",";
            }
            cout << endl;
        }
    }

};



void BFS(map <int, set<int>> &adjList, map <int, int> &indegree, queue <int> &q)
{
    while( !q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        
        for(auto &i : adjList[front])
        {
            indegree[i]-- ;
            if(indegree[i] == 0)
                q.push(i);
        }
    }
}



void topo_sort_BFS(map <int, set<int>> adjList, int nodes)
{
    map <int, int> indegree;

    
    // initialize indegree to 0 for all nodes
    for(int i = 1; i<= nodes; i++)
        indegree[i] = 0;


    // Find indegree
    for(auto &i : adjList){
        for(auto &j : i.second)
            indegree[j]++;
    }

    // queue m push kro
    queue <int> q;

    for(int i =1; i <= nodes; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    cout << "Topological sort is: " << endl;

    BFS(adjList, indegree, q);
    cout << endl;
}




int main()
{
    int nodes, edges;
    cout << "Enter the No. of nodes: " << endl;
    cin >> nodes;

    cout << "Enter the no. of edges: " << endl;
    cin >> edges;

    Graph g;
    int u, v;
    cout << "Enter the graph: (u,v)" << endl;


    for(int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g.addEdge(u,v);
    }
    
    g.print();

    topo_sort_BFS(g.adjList, nodes);
    
    return 0;
}