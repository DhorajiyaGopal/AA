// Minimum Vertex Cover using Randomized Approximation
// Author: GitHub Copilot
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Graph represented as edge list
class Graph {
public:
    int V; // Number of vertices
    vector<pair<int, int>> edges;
    Graph(int V) : V(V) {}
    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }
};

// Randomized Approximation for Minimum Vertex Cover
vector<int> randomizedMVC(Graph& g) {
    vector<pair<int, int>> edges = g.edges;
    vector<bool> inCover(g.V, false);
    mt19937 rng(time(0));
    while (!edges.empty()) {
        // Pick a random edge
        uniform_int_distribution<int> dist(0, edges.size() - 1);
        int idx = dist(rng);
        int u = edges[idx].first;
        int v = edges[idx].second;
        // Add both endpoints to cover
        inCover[u] = true;
        inCover[v] = true;
        // Remove all edges incident to u or v
        edges.erase(remove_if(edges.begin(), edges.end(),
            [u, v](pair<int, int> e) {
                return e.first == u || e.second == u || e.first == v || e.second == v;
            }), edges.end());
    }
    // Collect vertices in cover
    vector<int> cover;
    for (int i = 0; i < g.V; ++i) {
        if (inCover[i]) cover.push_back(i);
    }
    return cover;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    Graph g(V);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    vector<int> cover = randomizedMVC(g);
    cout << "Approximate Minimum Vertex Cover:\n";
    for (int v : cover) cout << v << " ";
    cout << endl;
    return 0;
}
