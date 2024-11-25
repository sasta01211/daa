#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[node] = true;
    cout << char('A' + node) << " ";  // Convert index to corresponding letter

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            dfs(i, adjMatrix, visited);
        }
    }
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

    vector<bool> visited(V, false);
    
    cout << "DFS starting from node B (1): ";
    dfs(1, adjMatrix, visited); // Start from node B (1)
    cout << endl;
    
    return 0;
}
