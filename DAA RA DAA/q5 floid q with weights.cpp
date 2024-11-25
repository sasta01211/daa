#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 5, 30, 15},
        {INT_MAX, 0, 5, INT_MAX},
        {15, INT_MAX, 0, 10},
        {INT_MAX, INT_MAX, 15, 0}
    };

    floydWarshall(graph);

    cout << "All Pairs Shortest Paths:\n";
    for (auto row : graph) {
        for (int cell : row) {
            cout << (cell == INT_MAX ? "INF" : to_string(cell)) << " ";
        }
        cout << "\n";
    }

    return 0;
}