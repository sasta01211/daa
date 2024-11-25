#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>& adjMatrix, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS starting from node B (1): ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << char('A' + node) << " ";  // Convert index to corresponding letter

        for (int i = 0; i < V; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 0, 1}, // a
        {1, 0, 1, 1, 1}, // b
        {0, 1, 0, 1, 0}, // c
        {0, 1, 1, 0, 1}, // d
        {1, 1, 0, 1, 0}  // e
    };

    bfs(1, adjMatrix, V); // Start from node B (1)
    
    return 0;
}
