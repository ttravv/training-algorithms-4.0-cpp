#include <iostream>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

// Функция для нахождения кратчайшего пути с помощью алгоритма Дейкстры
vector<int> shortest_path(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    distance[start] = 0;

    for (int k = 0; k < n; ++k) {
        int min_dist = numeric_limits<int>::max();
        int min_index = -1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && distance[i] < min_dist) {
                min_dist = distance[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            break;
        }

        visited[min_index] = true;

        for (int i = 0; i < n; ++i) {
            if (graph[min_index][i] != -1 && distance[min_index] + graph[min_index][i] < distance[i]) {
                distance[i] = distance[min_index] + graph[min_index][i];
                parent[i] = min_index;
            }
        }
    }

    // Восстановление пути
    vector<int> path;
    int cur = end;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    return (distance[end] != numeric_limits<int>::max()) ? path : vector<int>();
}

int main() {
    int N, S, F;
    cin >> N >> S >> F;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }
    vector<int> result = shortest_path(graph, S - 1, F - 1);
    if (!result.empty()) {
        for (int v : result) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
