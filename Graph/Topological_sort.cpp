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


void DFS(map< int, set<int>> &adjList, map <int, bool> &visited, int node, stack<int> &st)
{
    visited[node] = true;
    for(auto &i : adjList[node])
    {
        if(! visited[i])
            DFS(adjList, visited, i, st);
    }

    st.push(node);
}

void topo_sort(map< int, set<int>> adjList)
{
    map <int, bool> visited;
    stack <int> st;

    for(auto &i : adjList)
        visited[i.first] = false;
    
    for(auto &i : adjList)
    {
        int node = i.first;
        if(! visited[node])
        {
            DFS(adjList, visited, node, st);
        }
    }

    cout << "Topological sort of the following graph is: " << endl;

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

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


    for(int i = 0; i< edges; i++)
    {
        cin >> u >> v;
        g.addEdge(u,v);
    }
    
    // Print adj List
    g.print();

    // DFS
    topo_sort(g.adjList);
    
    return 0;
}