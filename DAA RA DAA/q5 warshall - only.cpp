#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transitiveClosure(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> A(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] |= (A[i][k] && A[k][j]);
            }
        }
    }

    return A;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    vector<vector<int>> closure = transitiveClosure(graph);

    cout << "Transitive Closure:\n";
    for (auto row : closure) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}