#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class graph
{
    public:
    map <int, set<int>>map;

    void addEdge( int u, int v, bool direction)
    {
        map[u].insert(v);
        if(direction == 0)
        {
            map[v].insert(u);
        }
    }

    void printAdjList()
    {
        for(auto &i: map) 
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


int main()
{
    int n;
    cout << "Enter the no of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the no of edges: " << endl;
    cin >> m;

    graph g;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
    return 0;
}