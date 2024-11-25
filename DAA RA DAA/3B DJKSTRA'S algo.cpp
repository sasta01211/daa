#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to implement Dijkstra's algorithm
void dijkstra(const vector<vector<int>>& graph, int source, int vertices) {
    // Initialize distances with infinity
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0; // Distance to source is 0

    // Create a set to track vertices whose shortest distance is finalized
    vector<bool> visited(vertices, false);

    for (int count = 0; count < vertices - 1; ++count) {
        // Find the vertex with the minimum distance that hasn't been visited yet
        int minDist = INT_MAX, minVertex;
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = true;

        // Update the distances of the adjacent vertices of the selected vertex
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && graph[minVertex][v] != 0 && dist[minVertex] != INT_MAX && dist[minVertex] + graph[minVertex][v] < dist[v]) {
                dist[v] = dist[minVertex] + graph[minVertex][v];
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from vertex " << source << " are:\n";
    for (int i = 0; i < vertices; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    // Graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 20},
        {10, 0, 10, 0, 0},
        {0, 10, 0, 30, 0},
        {0, 0, 30, 0, 0},
        {20, 0, 0, 0, 0}
    };

    int vertices = 5;
    int source = 0; // Source vertex

    // Run Dijkstra's algorithm
    dijkstra(graph, source, vertices);

    return 0;
}
