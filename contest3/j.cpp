/*#include <algorithm>
#include <iostream>
#include <vector>

struct Dest {
  int to;
  size_t weight;
};

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, size_t);
  size_t FindAllDist(int, int);

 private:
  size_t Dijkstra(int, int);
  std::vector<std::vector<Dest>> adjacency_list_;
  int size_;
  const size_t k_max_dist_ = 100000000;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  int start = 0, finish = 0;
  std::cin >> n >> start >> finish;
  start--;
  finish--;
  Graph graph(n);
  int weight = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> weight;
      if (weight == -1 || weight == 0) {
        continue;
      }
      graph.AddEdge(i, j, weight);
    }
  }
  size_t distance = graph.FindAllDist(start, finish);
  if (distance == 100000000) {
    std::cout << -1;
  } else {
    std::cout << distance;
  }
  return 0;
}
Graph::Graph(int size) : adjacency_list_(size), size_(size) {
}
void Graph::AddEdge(int from, int to, size_t weight) {
  adjacency_list_[from].push_back({to, weight});
}
size_t Graph::FindAllDist(int start, int finish) {
  return Dijkstra(start, finish);
}
size_t Graph::Dijkstra(int start, int finish) {
  std::vector<size_t> dist(size_, k_max_dist_);
  std::vector<bool> used(size_, false);
  dist[start] = 0;
  int min_dist_size = 0;
  while (size_ != min_dist_size) {
    int vertex = -1;
    for (int j = 0; j < size_; j++) {
      if (!used[j] && (vertex == -1 || dist[j] < dist[vertex])) {
        vertex = j;
      }
    }
    used[vertex] = true;
    min_dist_size++;
    for (auto& edge : adjacency_list_[vertex]) {
      if (!used[edge.to] && dist[vertex] + edge.weight < dist[edge.to]) {
        dist[edge.to] = dist[vertex] + edge.weight;
      }
    }
  }
  return dist[finish];
}*/