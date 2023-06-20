/*#include <iostream>
#include <vector>

struct Edge {
  int from;
  int to;
  int weight;
};

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  std::vector<int> FordBellman(int, int);

 private:
  bool Relax(std::vector<int>&, const Edge&);
  const int k_max_dist_ = 1000000;
  const int k_number_vertices_;
  std::vector<int> dist_;
  std::vector<Edge> edges_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  int k = 0, start = 0, finish = 0;
  std::cin >> k >> start >> finish;
  start--;
  finish--;
  int from = 0, to = 0, weight = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, weight);
  }
  std::vector<int> distance = graph.FordBellman(start, k);
  if (distance[finish] == 1000000) {
    std::cout << -1;
  } else {
    std::cout << distance[finish];
  }
  return 0;
}

Graph::Graph(int number_vertices) : k_number_vertices_(number_vertices) {
}
void Graph::AddEdge(int from, int to, int weight) {
  edges_.push_back({from, to, weight});
}
std::vector<int> Graph::FordBellman(int start, int k) {
  dist_.resize(k_number_vertices_, k_max_dist_);
  dist_[start] = 0;
  std::vector<int> dist_copy(dist_);
  for (int i = 0; i < k; i++) {
    std::vector<int> tmp(dist_);
    for (auto& edge : edges_) {
      if (Relax(tmp, edge)) {
        dist_copy[edge.to] = std::min(dist_copy[edge.to], tmp[edge.to]);
        tmp[edge.to] = dist_[edge.to];
      }
    }
    dist_ = dist_copy;
  }
  return dist_;
}
bool Graph::Relax(std::vector<int>& dist_copy, const Edge& edge) {
  if (dist_copy[edge.from] == k_max_dist_) {
    return false;
  }
  if (dist_copy[edge.to] > dist_copy[edge.from] + edge.weight) {
    dist_copy[edge.to] = dist_copy[edge.from] + edge.weight;
    return true;
  }
  return false;
}*/