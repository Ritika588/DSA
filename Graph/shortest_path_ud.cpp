/* The idea is to make a parent map and traverse using bfs.
    Then starting from the end node, find its paarent and keep repeating till u reach the source node.
    u will get the answer in reverse format*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public: 
    map <int, set<int>>adjList;
    map <int, bool> visited;
    map< int, int> parent;
    queue <int> q;

    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }  

    void printList()
    {
        for(auto &i: adjList)
        {
            cout << i.first << "->" ;
            for(auto &j : i.second)
            {
                cout << j << "," ;
            }
            cout << endl;
        }

    }


    // BFS CODE
    void traverse()
    {
        for(auto &i: adjList)
            visited[i.first] = false;

        for(auto &i: adjList)
        {
            if(visited[i.first])
                continue;

            q.push(i.first);
            parent[i.first] = -1;
            visited[i.first] = true;
            
            while(! q.empty())
            {
                int front = q.front();
                q.pop();

                for(auto &j : adjList[front])
                {
                    if(! visited[j])
                    {
                        q.push(j);
                        parent[j] = front;
                        visited[j] = true;
                    }

                }

            }
        }
    }



    void shortest_dist(int source_node, int end_node, vector <int> &path)
    {
        int curr_node = end_node;
        while(curr_node != source_node)
        {
            path.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        path.push_back(source_node);
    }


};


int main()
{
    int nodes, edges;

    cout << "Enter the no of node: " << endl;
    cin >> nodes;
    cout << "Enter the no of edges: " << endl;
    cin >> edges;

    cout << "enter the graph: " << endl;
    Graph g;

    for(int i =0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v);

    }
    // g.printList();

    g.traverse();

    int start_node, end_node;
    vector <int> path;

    cout << "Enter source and current node: " << endl;
    cin >> start_node >> end_node;

    g.shortest_dist(start_node, end_node, path);
    reverse (path.begin(), path.end());

    for(auto &i : path)
        cout << i << " ";


    return 0;
}