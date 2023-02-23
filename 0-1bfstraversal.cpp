#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>
#include<deque>
using namespace std ;

// 0-1 bfs to find shortest distance from source node to destination node

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addedge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
        pair<int, int> q = make_pair(u, weight);
        adj[v].push_back(q);
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "]";
            }
            cout << endl;
        }
    }

    void sdbfs(vector<int> &d, int vertices, int src)
    {
        for (int i = 0; i < vertices; i++)
        {
            d[i] = INT_MAX;
        }
        d[src] = 0;
        deque<int>q;
        q.push_front(src);
        while (!q.empty())
        {
            int v = q.front();
            q.pop_front();
            for (auto edge : adj[v])
            {
                int u = edge.first;
                int w = edge.second;
                if (d[v] + w < d[u])
                {
                    d[u] = d[v] + w;
                    if (w == 1)
                        q.push_back(u);
                    else
                        q.push_front(u);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addedge(0, 1, 1);
    g.addedge(0, 2, 1);
    g.addedge(0, 3, 1);
    g.addedge(0,4,0);
    g.addedge(1, 2, 1);
    g.addedge(3, 4, 0);

    g.print();
    int n = 5;

    int src;
    cin >> src;

    vector<int> dist(n);
    g.sdbfs(dist, n, src);

    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
}
