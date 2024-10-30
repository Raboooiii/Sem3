#include <iostream>
using namespace std;

const int MAX = 1000;
const int INF = 100000;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge edges[MAX];

    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int index, int u, int v, int w) {
        edges[index].src = u;
        edges[index].dest = v;
        edges[index].weight = w;
    }

    int findParent(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(int parent[], int rank[], int x, int y) {
        int xroot = findParent(parent, x);
        int yroot = findParent(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void kruskalMST() {
        Edge result[MAX];
        int parent[MAX], rank[MAX];

        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < E - 1; i++) {
            for (int j = i + 1; j < E; j++) {
                if (edges[i].weight > edges[j].weight) {
                    Edge temp = edges[i];
                    edges[i] = edges[j];
                    edges[j] = temp;
                }
            }
        }

        int e = 0; 
        for (int i = 0; e < V - 1 && i < E; i++) {
            Edge nextEdge = edges[i];
            int x = findParent(parent, nextEdge.src);
            int y = findParent(parent, nextEdge.dest);

            if (x != y) {
                result[e++] = nextEdge;
                unionSets(parent, rank, x, y);
            }
        }

        printMST(result, e);
    }

    void printMST(Edge result[], int e) {
        cout << "Edge \tWeight\n";
        for (int i = 0; i < e; i++)
            cout << result[i].src << " - " << result[i].dest << "\t   " << result[i].weight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    Graph graph(V, E);

    cout << "Enter the edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(i, u, v, w);
    }

    graph.kruskalMST();
    return 0;
}

