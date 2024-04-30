#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

void dfs(int u, vector<bool>& visited, vector<int>& path, int weight, const vector<vector<int>>& graph, int N, int& min_weight) {
    if (path.size() == N) {
        min_weight = min(min_weight, weight + graph[u][0]);  // Добавляем вес ребра обратно к вершине 1
        return;
    }
    for (int v = 0; v < N; ++v) {
        if (!visited[v] && graph[u][v] != 0) {
            visited[v] = true;
            path.push_back(v);
            dfs(v, visited, path, weight + graph[u][v], graph, N, min_weight);
            visited[v] = false;
            path.pop_back();
        }
    }
}

int hungarian(const vector<vector<int>>& graph, int N) {
    int min_weight = INF;
    vector<bool> visited(N, false);
    visited[0] = true;  // Начинаем с вершины 1
    vector<int> path = { 0 };
    dfs(0, visited, path, 0, graph, N, min_weight);
    return (min_weight != INF) ? min_weight : -1;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }
    int result = hungarian(graph, N);
    cout << result << endl;
    return 0;
}
