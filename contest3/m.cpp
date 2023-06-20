/*#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  std::vector<std::vector<int>> FloydWarshall();

 private:
  std::vector<std::vector<int>> matrix_adjacency_;
  int size_;
};

int main() {
  int n = 0;
  std::cin >> n;
  Graph graph(n);
  int weight = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> weight;
      graph.AddEdge(i, j, weight);
    }
  }
  std::vector<std::vector<int>> dist = graph.FloydWarshall();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << dist[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

Graph::Graph(int size) : matrix_adjacency_(size), size_(size) {
  for (int i = 0; i < size; i++) {
    matrix_adjacency_[i].resize(size);
  }
}

void Graph::AddEdge(int from, int to, int weight) {
  matrix_adjacency_[from][to] = weight;
}
std::vector<std::vector<int>> Graph::FloydWarshall() {
  std::vector<std::vector<int>> dist(matrix_adjacency_);
  for (int k = 0; k < size_; k++) {
    for (int x = 0; x < size_; x++) {
      for (int y = 0; y < size_; y++) {
        dist[x][y] = std::min(dist[x][y], dist[x][k] + dist[k][y]);
      }
    }
  }
  return dist;
}*/