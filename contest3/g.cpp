/*#include <iostream>
#include <vector>

class Graph {
 public:
  Graph(int, int);
  void AddEdge(int, int, int);
  std::vector<int> FordBellman(int);

 private:
  struct Edge {
    int from;
    int to;
    int weight;
  };
  bool Relax(const Edge&);
  const int k_max_dist_ = 30000;
  const int k_number_vertices_;
  std::vector<int> dist_;
  std::vector<int> prev_;
  std::vector<Edge> edges_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  int from = 0, to = 0, weight = 0;
  Graph graph(n, m);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, weight);
  }
  std::vector<int> distance = graph.FordBellman(0);
  for (auto& dist : distance) {
      std::cout << dist << ' ';
  }
  return 0;
}

Graph::Graph(int number_vertices, int number_edges) : k_number_vertices_(number_vertices), edges_(number_edges) {
}
void Graph::AddEdge(int from, int to, int weight) {
  edges_.push_back({from, to, weight});
}
std::vector<int> Graph::FordBellman(int start) {
  dist_.resize(k_number_vertices_, k_max_dist_);
  prev_.resize(k_number_vertices_, -1);
  dist_[start] = 0;
  for (int i = 0; i < k_number_vertices_; i++) {
    for (auto& edge : edges_) {
      Relax(edge);
    }
  }
  return dist_;
}
bool Graph::Relax(const Edge& edge) {
  if (dist_[edge.from] == k_max_dist_) {
    return false;
  }
  if (dist_[edge.to] > dist_[edge.from] + edge.weight) {
    dist_[edge.to] = dist_[edge.from] + edge.weight;
    return true;
  }
  return false;
}*/