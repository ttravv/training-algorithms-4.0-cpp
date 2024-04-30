#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Функция для нахождения кратчайшего расстояния между вершинами с помощью алгоритма Дейкстры
int shortest_path(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, numeric_limits<int>::max());
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
            }
        }
    }

    return (distance[end] != numeric_limits<int>::max()) ? distance[end] : -1;
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
    int result = shortest_path(graph, S - 1, F - 1);
    cout << result << endl;
    return 0;
}
