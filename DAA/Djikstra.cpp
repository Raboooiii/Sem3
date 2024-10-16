#include <iostream>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
    int min = 10000, min_index;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printSolution(int dist[], int V) {
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[][9], int src, int V) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = 10000;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != 10000 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}

int main() {
    int graph[9][9];
    int V = 9;
    cout << "Enter the values of the matrix: ";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cin >> src;
    dijkstra(graph, src, V);
    return 0;
}

