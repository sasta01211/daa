#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isConnected(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[node][neighbor] && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

int root(vector<int>& parent, int x) {
    return (parent[x] == x) ? x : (parent[x] = root(parent, parent[x]));
}

vector<pair<int, pair<int, int>>> kruskal(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                edges.emplace_back(graph[i][j], make_pair(i, j));
            }
        }
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> mst;
    for (auto& edge : edges) {
        int u = root(parent, edge.second.first);
        int v = root(parent, edge.second.second);
        if (u != v) {
            mst.push_back(edge);
            parent[u] = v;
        }
    }

    return mst;
}

vector<pair<int, pair<int, int>>> prim(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<pair<int, pair<int, int>>> mst;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, -1}});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (!visited[node]) {
            visited[node] = true;
            if (parent != -1) {
                mst.emplace_back(weight, make_pair(parent, node));
            }

            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (graph[node][neighbor]) {
                    pq.push({graph[node][neighbor], {neighbor, node}});
                }
            }
        }
    }

    return mst;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };

    if (isConnected(graph)) {
        cout << "Graph is connected.\n";

        vector<pair<int, pair<int, int>>> prim_mst = prim(graph);
        cout << "Prim's MST:\n";
        for (auto& edge : prim_mst) {
            cout << edge.second.first << " - " << edge.second.second << " (weight: " << edge.first << ")\n";
        }
        int prim_weight = 0;
        for (auto& edge : prim_mst) {
            prim_weight += edge.first;
        }
        cout << "Total weight: " << prim_weight << "\n";

        vector<pair<int, pair<int, int>>> kruskal_mst = kruskal(graph);
        cout << "Kruskal's MST:\n";
        for (auto& edge : kruskal_mst) {
            cout << edge.second.first << " - " << edge.second.second << " (weight: " << edge.first << ")\n";
        }
        int kruskal_weight = 0;
        for (auto& edge : kruskal_mst) {
            kruskal_weight += edge.first;
        }
        cout << "Total weight: " << kruskal_weight << "\n";
    } else {
        cout << "Graph is not connected.\n";
    }

    return 0;
}