#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Disjoint Set Union
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false; // Would create a cycle

        // Union by rank
        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;

        return true;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });

    DSU dsu(V);

    int mstWeight = 0;
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            mstWeight += edge.weight;

            if (mst.size() == V - 1)
                break;
        }
    }

    if (mst.size() != V - 1) {
        cout << "MST does not exist\n";
        return 0;
    }

    cout << "Edges in MST:\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v
             << " : " << edge.weight << '\n';
    }

    cout << "Minimum cost = " << mstWeight << '\n';

    return 0;
}