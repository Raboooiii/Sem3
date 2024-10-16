#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void BellmanFord(vector<Edge>& edges, int V, int E, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout << "Graph contains negative weight cycle" << endl;
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter the edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    BellmanFord(edges, V, E, src);
    return 0;
}

